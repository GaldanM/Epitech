package theleatherguy.contactsmanager.database;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

public class DatabaseHandler extends SQLiteOpenHelper
{
	public static final String TABLE_NAME = "contacts";
	public static final String COLUMN_ID = "id";
	public static final String COLUMN_FIRSTNAME = "firstName";
	public static final String COLUMN_LASTNAME = "lastName";
	public static final String COLUMN_HOMEPHONE = "homePhone";
	public static final String COLUMN_MOBILEPHONE = "mobilePhone";
	public static final String COLUMN_EMAIL = "email";

	private static final String TABLE_DROP = "DROP TABLE IF EXISTS " + TABLE_NAME;
	private static final String DATABASE_CREATE = "CREATE TABLE " + TABLE_NAME + "(" +
			COLUMN_ID + " INTEGER PRIMARY KEY," +
			COLUMN_FIRSTNAME + " TEXT NOT NULL," +
			COLUMN_LASTNAME + " TEXT NOT NULL," +
			COLUMN_HOMEPHONE + " TEXT NOT NULL," +
			COLUMN_MOBILEPHONE + " TEXT NOT NULL," +
			COLUMN_EMAIL + " TEXT NOT NULL)";

	DatabaseHandler(Context context, String name, SQLiteDatabase.CursorFactory factory, int version)
	{
		super(context, name, factory, version);
	}

	@Override
	public void onCreate(SQLiteDatabase db)
	{
		db.execSQL(DATABASE_CREATE);
	}

	@Override
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion)
	{
		db.execSQL(TABLE_DROP);
		onCreate(db);
	}
}
