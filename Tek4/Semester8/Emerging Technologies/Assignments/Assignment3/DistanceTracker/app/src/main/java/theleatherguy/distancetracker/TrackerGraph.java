package theleatherguy.distancetracker;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.support.v4.content.ContextCompat;
import android.util.AttributeSet;
import android.view.View;

import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.Map;

public class TrackerGraph extends View {
	private final DecimalFormat DF = new DecimalFormat("0.#");
	private final float[][] SCALES = new float[][]{
			{0, 5, 10, 15, 20, 30},
			{0, 10, 20, 30, 40, 50, 60},
			{0, 1, 2, 3, 4, 5},
			{0, 2, 4, 6, 8, 10},
			{0, 5, 10, 15, 20, 25, 30},
			{0, 10, 20, 30, 40, 50, 60},
			{0, 0.5f, 1, 1.5f, 2, 2.5f, 3},
			{0, 1, 2, 3, 4, 5, 6},
			{0, 2, 4, 6, 8, 10, 12},
			{0, 3, 6, 9, 12, 15, 18, 21, 24}
	};
	private final Map<String, Integer> UNITS_CONVERT = new HashMap<String, Integer>() {{
		put("secs", 1);
		put("mins", 60);
		put("hrs", 3600);
	}};
	private final int SPACE_TEXT = 200;
	private final int PADDING = 30;

	private int sideView;
	private int sideGraph;
	private int gapLine;
	private int barSize;

	private int scale;
	private String units;
	private long[] times = null;
	private Paint lines = new Paint();
	private Paint texts = new Paint();
	private Paint bars = new Paint();

	public TrackerGraph(Context context) {
		super(context);
		init();
	}

	public TrackerGraph(Context context, AttributeSet attrs) {
		super(context, attrs);
		init();
	}

	public TrackerGraph(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
		init();
	}

	private void init() {
		DF.setRoundingMode(RoundingMode.DOWN);

		lines.setFlags(Paint.ANTI_ALIAS_FLAG);
		lines.setStyle(Paint.Style.FILL_AND_STROKE);
		lines.setColor(ContextCompat.getColor(getContext(), R.color.lightGrey));
		lines.setStrokeWidth(4);

		texts.setFlags(Paint.ANTI_ALIAS_FLAG);
		texts.setStyle(Paint.Style.FILL);
		texts.setColor(ContextCompat.getColor(getContext(), R.color.darkGrey));
		texts.setTextSize(42);

		bars.setFlags(Paint.ANTI_ALIAS_FLAG);
		bars.setStyle(Paint.Style.FILL);
		bars.setColor(ContextCompat.getColor(getContext(), R.color.blue));
	}

	@Override
	protected void onDraw(Canvas canvas) {
		super.onDraw(canvas);

		int y = sideGraph + PADDING;
		for (float line : SCALES[scale]) {
			if (line > 0)
				canvas.drawText(DF.format(line) + " " + units, PADDING, y, texts);
			canvas.drawLine(SPACE_TEXT, y, sideView - PADDING, y, lines);
			y -= gapLine;
		}

		int x = SPACE_TEXT + (barSize) - (barSize / 2);
		for (long time : times) {
			float ratio = time / (SCALES[scale][SCALES[scale].length - 1] * UNITS_CONVERT.get(units));
			float top = sideGraph - (sideGraph * ratio);
			canvas.drawRect(x - (barSize / 3), top + PADDING, x + (barSize / 3), sideGraph + PADDING, bars);
			x += barSize;
		}
	}

	@Override
	protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
		sideView = MeasureSpec.getSize(widthMeasureSpec);
		sideGraph = sideView - SPACE_TEXT;

		if (times != null)
			setMeasures();

		setMeasuredDimension(sideView, sideView);

		invalidate();
	}

	public void giveTimes(long[] array) {
		times = array;
	}

	private void setMeasures() {
		long max = 0;
		for (long time : times) {
			if (time > max)
				max = time;
		}

		if (max < 30) {
			scale = 0;
			units = "secs";
		} else if (max < 60) {
			scale = 1;
			units = "secs";
		} else if (max < 300) {
			scale = 2;
			units = "mins";
		} else if (max < 600) {
			scale = 3;
			units = "mins";
		} else if (max < 1800) {
			scale = 4;
			units = "mins";
		} else if (max < 3600) {
			scale = 5;
			units = "mins";
		} else if (max < 10800) {
			scale = 6;
			units = "hrs";
		} else if (max < 21600) {
			scale = 7;
			units = "hrs";
		} else if (max < 43200) {
			scale = 8;
			units = "hrs";
		} else {
			scale = 9;
			units = "hrs";
		}
		gapLine = sideGraph / (SCALES[scale].length - 1);
		barSize = (sideGraph - PADDING) / times.length;
	}
}
