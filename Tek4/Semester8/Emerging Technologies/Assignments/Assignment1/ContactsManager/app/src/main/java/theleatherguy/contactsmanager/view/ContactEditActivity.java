package theleatherguy.contactsmanager.view;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.support.design.widget.TextInputEditText;
import android.support.design.widget.TextInputLayout;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

import theleatherguy.contactsmanager.R;
import theleatherguy.contactsmanager.database.DatabaseHandler;
import theleatherguy.contactsmanager.database.MyDatabase;
import theleatherguy.contactsmanager.model.Contact;

public class ContactEditActivity extends AppCompatActivity {
	private Toolbar toolbar;
	private TextInputLayout lFirstName;
	private TextInputLayout lLastName;
	private TextInputLayout lHomePhone;
	private TextInputLayout lMobilePhone;
	private TextInputLayout lEmail;
	private TextInputEditText editFirstName;
	private TextInputEditText editLastName;
	private TextInputEditText editHomePhone;
	private TextInputEditText editMobilePhone;
	private TextInputEditText editEmail;
	private MyDatabase db = null;

	int id;
	boolean isNew = false;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_contact_edit);

		initComponents();
		setListeners();
	}

	private void initComponents() {
		Intent intent = getIntent();
		String name = intent.getExtras().getString("firstName") + " " + intent.getExtras().getString("lastName");

		toolbar = (Toolbar) findViewById(R.id.contactEditToolbar);
		if (name.equals(" ")) {
			name = getResources().getString(R.string.activity_detail_name);
			isNew = true;
		}
		toolbar.setNavigationIcon(R.drawable.ic_action_cancel);
		toolbar.setTitle(name);
		setSupportActionBar(toolbar);

		db = new MyDatabase(getApplicationContext());

		lFirstName = (TextInputLayout) findViewById(R.id.labelFirstName);
		editFirstName = (TextInputEditText) findViewById(R.id.editFirstName);

		lLastName = (TextInputLayout) findViewById(R.id.labelLastName);
		editLastName = (TextInputEditText) findViewById(R.id.editLastName);

		lHomePhone = (TextInputLayout) findViewById(R.id.labelHomePhone);
		editHomePhone = (TextInputEditText) findViewById(R.id.editHomePhone);

		lMobilePhone = (TextInputLayout) findViewById(R.id.labelMobilePhone);
		editMobilePhone = (TextInputEditText) findViewById(R.id.editMobilePhone);

		lEmail = (TextInputLayout) findViewById(R.id.labelEmail);
		editEmail = (TextInputEditText) findViewById(R.id.editEmail);

		if (!isNew) {
			id = Integer.parseInt(intent.getExtras().getString("ID"));

			lFirstName.setHintAnimationEnabled(false);
			editFirstName.setText(intent.getExtras().getString("firstName"));

			lLastName.setHintAnimationEnabled(false);
			editLastName.setText(intent.getExtras().getString("lastName"));

			lHomePhone.setHintAnimationEnabled(false);
			editHomePhone.setText(intent.getExtras().getString("homePhone"));

			lMobilePhone.setHintAnimationEnabled(false);
			editMobilePhone.setText(intent.getExtras().getString("mobilePhone"));

			lEmail.setHintAnimationEnabled(false);
			editEmail.setText(intent.getExtras().getString("email"));
		}
	}

	private void setListeners() {
		toolbar.setNavigationOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				finish();
			}
		});
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		getMenuInflater().inflate(R.menu.menu_contact_edit, menu);

		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		switch (item.getItemId()) {
			case R.id.action_save:
				String firstName = editFirstName.getText().toString().trim();
				String lastName = editLastName.getText().toString().trim();
				String homePhone = editHomePhone.getText().toString().trim();
				String mobilePhone = editMobilePhone.getText().toString().trim();
				String email = editEmail.getText().toString().trim();

				if (setErrorEditName(lFirstName, firstName) &
						setErrorEditName(lLastName, lastName) &
						setErrorEditPhone(lHomePhone, homePhone) &
						setErrorEditPhone(lMobilePhone, mobilePhone) &
						setErrorEditEmail(lEmail, email) &
						setErrorDuplicate(lFirstName, lLastName, firstName, lastName))
					saveChanges(firstName, lastName, homePhone, mobilePhone, email);
				break;
		}
		return super.onOptionsItemSelected(item);
	}

	private boolean setErrorEditName(TextInputLayout edit, String name) {
		if (name.isEmpty()) {
			edit.setErrorEnabled(true);
			edit.setError("This field is required");
			return (false);
		} else if (!name.matches("[a-zA-Z()\\-']+")) {
			edit.setErrorEnabled(true);
			edit.setError("Only letters");
			return (false);
		}
		edit.setErrorEnabled(false);
		return (true);
	}

	private boolean setErrorEditPhone(TextInputLayout edit, String phone) {
		if (phone.isEmpty()) {
			edit.setErrorEnabled(true);
			edit.setError("This field is required");
			return (false);
		} else if (!phone.matches("[0-9+() ]+")) {
			edit.setErrorEnabled(true);
			edit.setError("Only digits");
			return (false);
		}
		edit.setErrorEnabled(false);
		return (true);
	}

	private boolean setErrorEditEmail(TextInputLayout edit, String email) {
		if (email.isEmpty()) {
			edit.setErrorEnabled(true);
			edit.setError("This field is required");
			return (false);
		} else if (!email.matches("[a-zA-Z0-9._%-]+@[a-zA-Z0-9]+\\.[a-zA-Z]{2,4}")) {
			edit.setErrorEnabled(true);
			edit.setError("Not a valid email");
			return (false);
		}
		edit.setErrorEnabled(false);
		return (true);
	}

	private boolean setErrorDuplicate(TextInputLayout first, TextInputLayout last, String firstN, String lastN) {
		Cursor cursor;
		SQLiteDatabase datab;

		if (!first.isErrorEnabled() && !last.isErrorEnabled()) {
			datab = db.openToRead();
			String query = "SELECT COUNT(*) FROM " + DatabaseHandler.TABLE_NAME + " WHERE UPPER(" +
					DatabaseHandler.COLUMN_FIRSTNAME + ")=\"" + firstN.toUpperCase() + "\" AND UPPER(" +
					DatabaseHandler.COLUMN_LASTNAME + ")=\"" + lastN.toUpperCase() + "\" AND " +
					DatabaseHandler.COLUMN_ID + "!=" + id;
			cursor = datab.rawQuery(query, null);
			cursor.moveToFirst();
			if (cursor.getInt(0) > 0) {
				first.setErrorEnabled(true);
				first.setError("Already exists");
				last.setErrorEnabled(true);
				last.setError("Already exists");
				cursor.close();
				datab.close();
				return (false);
			}
			cursor.close();
			datab.close();
		}
		return (true);
	}

	@Override
	public void onBackPressed() {
		super.onBackPressed();
		finish();
	}

	private void saveChanges(String firstName, String lastName, String homePhone, String mobilePhone, String email) {
		db.openToWrite();
		if (isNew)
			db.add(new Contact(id, firstName, lastName, homePhone, mobilePhone, email));
		else
			db.change(id, new Contact(id, firstName, lastName, homePhone, mobilePhone, email));
		db.close();
		finish();
	}
}
