package theleatherguy.contactsmanager.view;

import android.animation.AnimatorSet;
import android.animation.ObjectAnimator;
import android.os.Bundle;
import android.support.v4.app.DialogFragment;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.view.WindowManager;
import android.widget.TextView;

import theleatherguy.contactsmanager.R;

public class ContactListDialog extends DialogFragment {
	View rootView;
	TextView tEdit;
	TextView tDelete;
	IListeners interf;

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
		rootView = inflater.inflate(R.layout.dialog_action_contact, container, false);
		tEdit = (TextView) rootView.findViewById(R.id.tEdit);
		tDelete = (TextView) rootView.findViewById(R.id.tDelete);

		tEdit.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				if (interf != null) {
					interf.onEdit();
					dismiss();
				}
			}
		});

		tDelete.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				if (interf != null) {
					interf.onDelete();
					dismiss();
				}
			}
		});


		Window w = getDialog().getWindow();
		if (w != null) {
			WindowManager.LayoutParams params = w.getAttributes();
			params.gravity = Gravity.BOTTOM | Gravity.CENTER_HORIZONTAL;
			w.setAttributes(params);
		}

		AnimatorSet set = new AnimatorSet();

		ObjectAnimator translate = ObjectAnimator.ofFloat(rootView, "translationY", 500, 0);
		translate.setDuration(400);

		ObjectAnimator fadeIn = ObjectAnimator.ofFloat(rootView, "alpha", 0, 1);
		fadeIn.setDuration(400);

		set.play(translate).with(fadeIn);

		set.start();

		return rootView;
	}

	public void setListeners(IListeners inter) {
		interf = inter;
	}

	interface IListeners {
		void onEdit();

		void onDelete();
	}
}