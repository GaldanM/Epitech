package theleatherguy.distancetracker;

import android.content.Context;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;

@SuppressWarnings("MissingPermission")
class MyLocation {
	private LocationManager lm;
	private LocationResult locationResult;

	private LocationListener locationListenerGps = new LocationListener() {
		public void onLocationChanged(Location location) {
			locationResult.gotLocation(location);
		}

		public void onProviderDisabled(String provider) {
		}

		public void onProviderEnabled(String provider) {
		}

		public void onStatusChanged(String provider, int status, Bundle extras) {
		}
	};

	private LocationListener locationListenerNetwork = new LocationListener() {
		public void onLocationChanged(Location location) {
			locationResult.gotLocation(location);
		}

		public void onProviderDisabled(String provider) {
		}

		public void onProviderEnabled(String provider) {
		}

		public void onStatusChanged(String provider, int status, Bundle extras) {
		}
	};

	MyLocation(LocationResult result) {
		locationResult = result;
	}

	boolean startLocation(Context context) {
		if (lm == null)
			lm = (LocationManager) context.getSystemService(Context.LOCATION_SERVICE);

		boolean gpsEnabled = lm.isProviderEnabled(LocationManager.GPS_PROVIDER);
		boolean networkEnabled = lm.isProviderEnabled(LocationManager.NETWORK_PROVIDER);

		if (!gpsEnabled && !networkEnabled)
			return false;

		if (gpsEnabled)
			lm.requestLocationUpdates(LocationManager.GPS_PROVIDER, 1000, 0, locationListenerGps);
		if (networkEnabled)
			lm.requestLocationUpdates(LocationManager.NETWORK_PROVIDER, 1000, 0, locationListenerNetwork);

		return true;
	}

	void stopLocation() {
		lm.removeUpdates(locationListenerGps);
		lm.removeUpdates(locationListenerNetwork);
	}

	static abstract class LocationResult {
		public abstract void gotLocation(Location location);
	}
}
