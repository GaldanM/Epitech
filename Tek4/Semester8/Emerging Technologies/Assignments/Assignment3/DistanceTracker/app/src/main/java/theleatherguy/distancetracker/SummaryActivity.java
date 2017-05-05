package theleatherguy.distancetracker;

import android.graphics.Color;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.Chronometer;
import android.widget.TextView;

import java.math.RoundingMode;
import java.text.DecimalFormat;

public class SummaryActivity extends AppCompatActivity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_summary);

		init();
	}

	private void init() {
		DecimalFormat DF = new DecimalFormat("0.#");
		DF.setRoundingMode(RoundingMode.DOWN);

		Toolbar toolbar = (Toolbar) findViewById(R.id.summaryToolbar);
		toolbar.setTitle(R.string.summary_title);
		toolbar.setTitleTextColor(Color.WHITE);
		toolbar.setNavigationIcon(R.drawable.ic_arrow_back);
		setSupportActionBar(toolbar);
		toolbar.setNavigationOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				finish();
			}
		});

		TextView tDistance = (TextView) findViewById(R.id.tDistance);
		TextView tAvgSpeed = (TextView) findViewById(R.id.tAvgSpeed);
		TextView tNoDistance = (TextView) findViewById(R.id.tNoDistance);
		Chronometer tTime = (Chronometer) findViewById(R.id.tTime);
		TrackerGraph graph = (TrackerGraph) findViewById(R.id.graph);

		Bundle bundle = getIntent().getExtras();

		tDistance.setText(getString(R.string.disp_dist, DF.format(bundle.getFloat("distance"))));
		tAvgSpeed.setText(getString(R.string.disp_speed, DF.format(bundle.getDouble("avgSpeed"))));
		tTime.setText(bundle.getString("duration"));

		long[] times = bundle.getLongArray("times");
		if (times != null && times.length > 0) {
			graph.setVisibility(View.VISIBLE);
			tNoDistance.setVisibility(View.GONE);
			graph.giveTimes(times);
		} else {
			graph.setVisibility(View.GONE);
			tNoDistance.setVisibility(View.VISIBLE);
		}
	}
}
