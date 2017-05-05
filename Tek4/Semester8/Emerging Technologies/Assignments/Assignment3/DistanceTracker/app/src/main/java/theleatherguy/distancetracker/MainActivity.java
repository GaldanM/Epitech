package theleatherguy.distancetracker;

import android.Manifest;
import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.drawable.TransitionDrawable;
import android.location.Location;
import android.os.Bundle;
import android.os.SystemClock;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.Chronometer;
import android.widget.TextView;
import android.widget.Toast;

import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Iterator;

public class MainActivity extends AppCompatActivity {
	private final int REQUEST_COARSE_LOCATION = 0;
	private final int REQUEST_FINE_LOCATION = 1;
	private final DecimalFormat DF = new DecimalFormat("0.#");

	private TextView tSpeed, tDistance, tAvgSpeed;
	private Chronometer chrono;
	private Button bStartStop;
	private TransitionDrawable transition;
	MyLocation myLocation;

	private ArrayList<Long> historyTimes = new ArrayList<>();
	private ArrayList<Float> historySpeeds = new ArrayList<>();
	private Location previousPos = null;
	private float distanceTot = 0;
	private long prevKMTime = 0;
	private boolean started = false;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		initComponents();
		initListeners();
	}

	@Override
	public void onRequestPermissionsResult(int requestCode, @NonNull String permissions[], @NonNull int[] grantResults) {
		switch (requestCode) {
			case REQUEST_COARSE_LOCATION:
				if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED)
					initLocationListener();
			case REQUEST_FINE_LOCATION:
				if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED)
					initLocationListener();
		}
	}

	private void initComponents() {
		DF.setRoundingMode(RoundingMode.DOWN);

		tSpeed = (TextView) findViewById(R.id.tSpeed);
		tDistance = (TextView) findViewById(R.id.tDistance);
		tAvgSpeed = (TextView) findViewById(R.id.tAvgSpeed);

		chrono = (Chronometer) findViewById(R.id.chronometer);

		bStartStop = (Button) findViewById(R.id.bStartStop);
		transition = (TransitionDrawable) bStartStop.getBackground();
		transition.startTransition(0);
	}

	private void initListeners() {
		bStartStop.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				if (ActivityCompat.checkSelfPermission(getBaseContext(), Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED &&
						ActivityCompat.checkSelfPermission(getBaseContext(), Manifest.permission.ACCESS_COARSE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
					if (started) {
						myLocation.stopLocation();
						transition.startTransition(500);
						bStartStop.setText(getResources().getString(R.string.start));
						chrono.stop();
						startSummary();
					} else {
						myLocation.startLocation(getBaseContext());
						transition.reverseTransition(500);
						bStartStop.setText(getResources().getString(R.string.stop));
						chrono.setBase(SystemClock.elapsedRealtime());
						chrono.start();
					}
					started = !started;
				} else {
					Toast.makeText(getBaseContext(), "GPS is needed, allow it please", Toast.LENGTH_LONG).show();
				}
			}
		});
		initLocationListener();
	}

	private void initLocationListener() {
		if (ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED &&
				ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {

			ActivityCompat.requestPermissions(this,
					new String[]{Manifest.permission.ACCESS_FINE_LOCATION},
					REQUEST_FINE_LOCATION);

			ActivityCompat.requestPermissions(this,
					new String[]{Manifest.permission.ACCESS_COARSE_LOCATION},
					REQUEST_COARSE_LOCATION);
			return;
		}

		final Activity activity = this;

		MyLocation.LocationResult locationResult = new MyLocation.LocationResult() {
			@Override
			public void gotLocation(final Location location) {
				activity.runOnUiThread(new Runnable() {
					@Override
					public void run() {
						if (location != null) {
							updateDistance(location);
							updateSpeed(location);
							updateAvgSpeed();
						}
					}
				});
			}
		};
		myLocation = new MyLocation(locationResult);
	}

	private void updateDistance(Location location) {
		if (previousPos != null)
			distanceTot += location.distanceTo(previousPos) / 1000;
		else
			distanceTot = 0;
		previousPos = location;
		if (distanceTot >= historyTimes.size() + 1) {
			long point = SystemClock.elapsedRealtime() - (prevKMTime == 0 ? chrono.getBase() : prevKMTime);
			prevKMTime = SystemClock.elapsedRealtime();
			historyTimes.add(point / 1000);
		}
		tDistance.setText(getString(R.string.disp_dist, DF.format(distanceTot)));
	}

	private void updateSpeed(Location location) {
		float speed = location.getSpeed() * 3.6f;
		tSpeed.setText(getString(R.string.disp_speed, DF.format(speed)));
		historySpeeds.add(speed);
	}

	private void updateAvgSpeed() {
		tAvgSpeed.setText(getString(R.string.disp_speed, DF.format(getAverage())));
	}

	private double getAverage() {
		double sum = 0;

		for (Float f : historySpeeds)
			sum += f;

		if (sum > 0)
			return (sum / historySpeeds.size());
		else
			return 0;
	}

	private void reset() {
		distanceTot = 0;
		previousPos = null;
		prevKMTime = 0;
		chrono.setBase(SystemClock.elapsedRealtime());
		historyTimes.clear();
		historySpeeds.clear();
		tSpeed.setText(getString(R.string.disp_speed, "-"));
		tDistance.setText(getString(R.string.disp_dist, "-"));
		tAvgSpeed.setText(getString(R.string.disp_speed, "-"));
	}

	private void startSummary() {
		long[] array = new long[historyTimes.size()];
		Iterator<Long> iterator = historyTimes.iterator();

		for (int i = 0; i < array.length; i++) {
			array[i] = iterator.next();
		}

		Intent intent = new Intent(this, SummaryActivity.class);
		intent.putExtra("distance", distanceTot);
		intent.putExtra("avgSpeed", getAverage());
		intent.putExtra("duration", chrono.getText());
		intent.putExtra("times", array);
		startActivity(intent);
		reset();
	}
}
