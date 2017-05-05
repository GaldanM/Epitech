package theleatherguy.androidbyexample;

import android.content.res.Resources;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private int clicks;
    private TextView tv_display;
    private Button btn_click;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        clicks = 0;
        tv_display = (TextView) findViewById(R.id.tv_display);
        tv_display.setText("Button has been clicked " + clicks + " times");
        btn_click.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                clicks++;
                tv_display.setText("Button has been clicked " + clicks + " times");
            }
        });
    }
}
