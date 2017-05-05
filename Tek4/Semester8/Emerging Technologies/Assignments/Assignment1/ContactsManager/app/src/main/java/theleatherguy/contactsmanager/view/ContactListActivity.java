package theleatherguy.contactsmanager.view;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v4.app.DialogFragment;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

import theleatherguy.contactsmanager.R;
import theleatherguy.contactsmanager.database.DatabaseHandler;
import theleatherguy.contactsmanager.database.MyDatabase;
import theleatherguy.contactsmanager.model.Contact;

public class ContactListActivity extends AppCompatActivity {
	private ListView list;
	private Button bContact;
	private FloatingActionButton fab;
	private List<Contact> contacts = new ArrayList<>();
	private MyDatabase db = null;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_contact_list);

		initComponents();
		setListeners();
	}

	@Override
	public void onResume() {
		super.onResume();
		loadDatabase();
	}

	private void initComponents() {
		Toolbar toolbar = (Toolbar) findViewById(R.id.contactListToolbar);
		toolbar.setTitle(getResources().getString(R.string.activity_list_name));
		setSupportActionBar(toolbar);

		bContact = (Button) findViewById(R.id.bContact);

		fab = (FloatingActionButton) findViewById(R.id.fab);

		list = (ListView) findViewById(R.id.contactList);
	}

	private void setListeners() {
		bContact.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View view) {
				goEdit(new Contact());
			}
		});

		fab.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View view) {
				goEdit(new Contact());
			}
		});

		list.setOnItemClickListener(new AdapterView.OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
				goDetails(contacts.get(position));
			}
		});

		list.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
			@Override
			public boolean onItemLongClick(AdapterView<?> parent, View view, final int position, long id) {
				ContactListDialog.IListeners interf = new ContactListDialog.IListeners() {
					@Override
					public void onEdit() {
						goEdit(contacts.get(position));
					}

					@Override
					public void onDelete() {
						db = new MyDatabase(getApplicationContext());
						db.openToWrite();
						db.delete(contacts.get(position).getId());
						loadDatabase();
					}
				};

				ContactListDialog dialog = new ContactListDialog();
				dialog.setListeners(interf);
				dialog.setStyle(DialogFragment.STYLE_NORMAL, R.style.You_Dialog);
				dialog.show(ContactListActivity.this.getSupportFragmentManager(), ContactListDialog.class.getSimpleName());

				return true;
			}
		});

		list.setEmptyView(findViewById(R.id.empty_contact_view));
	}

	private void loadDatabase() {
		Cursor cursor;
		SQLiteDatabase datab;

		contacts.clear();
		if (db == null)
			db = new MyDatabase(getApplicationContext());

		datab = db.openToRead();
		cursor = datab.rawQuery("SELECT * FROM " + DatabaseHandler.TABLE_NAME, null);
		if (cursor.moveToFirst()) {
			while (!cursor.isAfterLast()) {
				int id = Integer.parseInt(cursor.getString(cursor.getColumnIndex(DatabaseHandler.COLUMN_ID)));
				String firstName = cursor.getString(cursor.getColumnIndex(DatabaseHandler.COLUMN_FIRSTNAME));
				String lastName = cursor.getString(cursor.getColumnIndex(DatabaseHandler.COLUMN_LASTNAME));
				String homePhone = cursor.getString(cursor.getColumnIndex(DatabaseHandler.COLUMN_HOMEPHONE));
				String mobilePhone = cursor.getString(cursor.getColumnIndex(DatabaseHandler.COLUMN_MOBILEPHONE));
				String email = cursor.getString(cursor.getColumnIndex(DatabaseHandler.COLUMN_EMAIL));
				contacts.add(new Contact(id, firstName, lastName, homePhone, mobilePhone, email));
				cursor.moveToNext();
			}
		}
		cursor.close();
		datab.close();

		List<String> names = new ArrayList<>();
		for (Contact contact : contacts)
			names.add(contact.getFirstName() + " " + contact.getLastName());
		ArrayAdapter adapter = new ArrayAdapter<>(ContactListActivity.this, android.R.layout.simple_list_item_1, names);
		list.setAdapter(adapter);
	}

	private void goEdit(Contact contact) {
		Intent intent = new Intent(getApplicationContext(), ContactEditActivity.class);
		intent.putExtra("ID", String.valueOf(contact.getId()));
		intent.putExtra("firstName", String.valueOf(contact.getFirstName()));
		intent.putExtra("lastName", String.valueOf(contact.getLastName()));
		intent.putExtra("homePhone", String.valueOf(contact.getHomePhone()));
		intent.putExtra("mobilePhone", String.valueOf(contact.getMobilePhone()));
		intent.putExtra("email", String.valueOf(contact.getEmail()));
		startActivity(intent);
	}

	private void goDetails(Contact contact) {
		Intent intent = new Intent(getApplicationContext(), ContactDetailsActivity.class);
		intent.putExtra("ID", String.valueOf(contact.getId()));
		startActivity(intent);
	}
}
