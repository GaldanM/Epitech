package theleatherguy.contactsmanager.view;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;

import theleatherguy.contactsmanager.R;
import theleatherguy.contactsmanager.database.DatabaseHandler;
import theleatherguy.contactsmanager.database.MyDatabase;
import theleatherguy.contactsmanager.model.Contact;

public class ContactDetailsActivity extends AppCompatActivity {
	TextView tFirstName;
	TextView tLastName;
	TextView tHomePhone;
	TextView tMobilePhone;
	TextView tEmail;
	Toolbar toolbar;

	private Contact contact;
	private MyDatabase db = null;
	private String id;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_contact_details);

		initComponents();
	}

	private void initComponents() {
		Intent intent = getIntent();
		id = intent.getExtras().getString("ID");

		tFirstName = (TextView) findViewById(R.id.textFirstName);
		tLastName = (TextView) findViewById(R.id.textLastName);
		tHomePhone = (TextView) findViewById(R.id.textHomePhone);
		tMobilePhone = (TextView) findViewById(R.id.textMobilePhone);
		tEmail = (TextView) findViewById(R.id.textEmail);

		contact = new Contact();

		loadContact();

		toolbar = (Toolbar) findViewById(R.id.contactDetailsToolbar);
		toolbar.setTitle(contact.getFirstName() + " " + contact.getLastName());
		toolbar.setNavigationIcon(R.drawable.ic_arrow_back);
		setSupportActionBar(toolbar);
		toolbar.setNavigationOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				finish();
			}
		});
	}

	private void loadContact() {
		Cursor cursor;
		SQLiteDatabase datab;

		if (db == null)
			db = new MyDatabase(getApplicationContext());

		datab = db.openToRead();
		String query = "SELECT * FROM " + DatabaseHandler.TABLE_NAME + " WHERE " + DatabaseHandler.COLUMN_ID + "=" + id;
		cursor = datab.rawQuery(query, null);
		if (cursor.moveToFirst()) {
			contact.setFirstName(cursor.getString(cursor.getColumnIndex(DatabaseHandler.COLUMN_FIRSTNAME)));
			contact.setLastName(cursor.getString(cursor.getColumnIndex(DatabaseHandler.COLUMN_LASTNAME)));
			contact.setHomePhone(cursor.getString(cursor.getColumnIndex(DatabaseHandler.COLUMN_HOMEPHONE)));
			contact.setMobilePhone(cursor.getString(cursor.getColumnIndex(DatabaseHandler.COLUMN_MOBILEPHONE)));
			contact.setEmail(cursor.getString(cursor.getColumnIndex(DatabaseHandler.COLUMN_EMAIL)));
		}
		cursor.close();
		datab.close();
		tFirstName.setText(contact.getFirstName());
		tLastName.setText(contact.getLastName());
		tHomePhone.setText(contact.getHomePhone());
		tMobilePhone.setText(contact.getMobilePhone());
		tEmail.setText(contact.getEmail());
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		getMenuInflater().inflate(R.menu.menu_contact_details, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		switch (item.getItemId()) {
			case R.id.action_edit:
				Intent intent = new Intent(getApplicationContext(), ContactEditActivity.class);
				intent.putExtra("ID", id);
				intent.putExtra("firstName", contact.getFirstName());
				intent.putExtra("lastName", contact.getLastName());
				intent.putExtra("homePhone", contact.getHomePhone());
				intent.putExtra("mobilePhone", contact.getMobilePhone());
				intent.putExtra("email", contact.getEmail());
				startActivity(intent);
		}
		return super.onOptionsItemSelected(item);
	}

	@Override
	public void onResume() {
		super.onResume();
		loadContact();
		toolbar.setTitle(contact.getFirstName() + " " + contact.getLastName());
	}

	@Override
	public void onBackPressed() {
		super.onBackPressed();
		finish();
	}
}
