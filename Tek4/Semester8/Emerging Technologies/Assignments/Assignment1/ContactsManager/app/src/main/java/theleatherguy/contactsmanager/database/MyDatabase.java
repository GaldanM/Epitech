package theleatherguy.contactsmanager.database;

import android.content.ContentValues;
import android.content.Context;
import android.database.sqlite.SQLiteDatabase;

import theleatherguy.contactsmanager.model.Contact;

public class MyDatabase
{
	protected final static int version = 1;
	protected final static String name = "database.db";

	private SQLiteDatabase database = null;
	private DatabaseHandler handler = null;

	public MyDatabase(Context context) {
		handler = new DatabaseHandler(context, name, null, version);
	}

	public SQLiteDatabase openToWrite() {
		database = handler.getWritableDatabase();
		return (database);
	}

	public SQLiteDatabase openToRead() {
		database = handler.getReadableDatabase();
		return (database);
	}

	public void close() {
		database.close();
	}

	public void add(Contact contact) {
		ContentValues value = new ContentValues();

		value.put(DatabaseHandler.COLUMN_FIRSTNAME, contact.getFirstName());
		value.put(DatabaseHandler.COLUMN_LASTNAME, contact.getLastName());
		value.put(DatabaseHandler.COLUMN_HOMEPHONE, contact.getHomePhone());
		value.put(DatabaseHandler.COLUMN_MOBILEPHONE, contact.getMobilePhone());
		value.put(DatabaseHandler.COLUMN_EMAIL, contact.getEmail());
		database.insert(DatabaseHandler.TABLE_NAME, null, value);
	}

	public void delete(int id) {
		database.delete(DatabaseHandler.TABLE_NAME, DatabaseHandler.COLUMN_ID + " = ?", new String[] {String.valueOf(id)});
	}

	public void change(int id, Contact contact) {
		ContentValues value = new ContentValues();

		value.put(DatabaseHandler.COLUMN_FIRSTNAME, contact.getFirstName());
		value.put(DatabaseHandler.COLUMN_LASTNAME, contact.getLastName());
		value.put(DatabaseHandler.COLUMN_HOMEPHONE, contact.getHomePhone());
		value.put(DatabaseHandler.COLUMN_MOBILEPHONE, contact.getMobilePhone());
		value.put(DatabaseHandler.COLUMN_EMAIL, contact.getEmail());
		database.update(DatabaseHandler.TABLE_NAME, value, DatabaseHandler.COLUMN_ID + " = ?", new String[] {String.valueOf(id)});
	}
}