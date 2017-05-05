package theleatherguy.reversi;

import android.content.res.Configuration;
import android.graphics.Color;
import android.graphics.drawable.Drawable;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
	private BoardGame boardGame;
	private GameEngine gameEngine = GameEngine.getInstance();
	private Drawable[] currentPlayers = new Drawable[2];
	private LinearLayout[] playerBoards = new LinearLayout[2];
	private TextView[] playerTurns = new TextView[2];
	private TextView[] playerScores = new TextView[2];
	private LinearLayout gameLinear;
	private Button bReset;
	private Button bQuit;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		initComponents();
	}

	private void initComponents() {
		boardGame = (BoardGame) findViewById(R.id.boardGame);

		currentPlayers[0] = ContextCompat.getDrawable(this, R.drawable.current_player_white);
		currentPlayers[1] = ContextCompat.getDrawable(this, R.drawable.current_player_black);

		playerBoards[0] = (LinearLayout) findViewById(R.id.layoutPlayer1);
		playerBoards[1] = (LinearLayout) findViewById(R.id.layoutPlayer2);
		playerBoards[1].setBackgroundDrawable(currentPlayers[1]);
		playerBoards[0].setBackgroundColor(ContextCompat.getColor(getBaseContext(), R.color.pieceWhite));

		playerTurns[0] = (TextView) findViewById(R.id.playerTurn1);
		playerTurns[1] = (TextView) findViewById(R.id.playerTurn2);

		playerScores[0] = (TextView) findViewById(R.id.playerScore1);
		playerScores[1] = (TextView) findViewById(R.id.playerScore2);

		bReset = (Button) findViewById(R.id.bReset);
		bQuit = (Button) findViewById(R.id.bQuit);

		gameLinear = (LinearLayout) findViewById(R.id.gameLinear);
		if (this.getResources().getConfiguration().orientation == Configuration.ORIENTATION_PORTRAIT)
			gameLinear.setOrientation(LinearLayout.VERTICAL);
		else if (this.getResources().getConfiguration().orientation == Configuration.ORIENTATION_LANDSCAPE)
			gameLinear.setOrientation(LinearLayout.HORIZONTAL);

		boardGame.setMainActivity(this);

		bReset.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				boardGame.reset();
			}
		});

		bQuit.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				finish();
			}
		});
	}

	public void updateScores(int[] scores){
		gameEngine.countScores();
		this.playerScores[Piece.WHITE].setText(String.valueOf(scores[Piece.WHITE]));
		this.playerScores[Piece.BLACK].setText(String.valueOf(scores[Piece.BLACK]));
	}

	public void changePlayer(int player) {
		if (player == Piece.WHITE) {
			playerBoards[0].setBackgroundDrawable(currentPlayers[0]);
			playerBoards[1].setBackgroundColor(ContextCompat.getColor(getBaseContext(), R.color.pieceBlack));
			playerTurns[Piece.WHITE].setVisibility(View.VISIBLE);
			playerTurns[Piece.BLACK].setVisibility(View.INVISIBLE);
		} else {
			playerBoards[1].setBackgroundDrawable(currentPlayers[1]);
			playerBoards[0].setBackgroundColor(ContextCompat.getColor(getBaseContext(), R.color.pieceWhite));
			playerTurns[Piece.BLACK].setVisibility(View.VISIBLE);
			playerTurns[Piece.WHITE].setVisibility(View.INVISIBLE);
		}
	}

	@Override
	public void onConfigurationChanged(Configuration newConfig) {
		super.onConfigurationChanged(newConfig);

		if (newConfig.orientation == Configuration.ORIENTATION_LANDSCAPE)
			gameLinear.setOrientation(LinearLayout.HORIZONTAL);
		else if (newConfig.orientation == Configuration.ORIENTATION_PORTRAIT)
			gameLinear.setOrientation(LinearLayout.VERTICAL);
	}
}
