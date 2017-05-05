package theleatherguy.reversi;

import android.content.Context;
import android.content.DialogInterface;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AlertDialog;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;

public class BoardGame extends View {
	private GameEngine gameEngine = GameEngine.getInstance();
	private MainActivity mainActivity;
	private int viewHeight;
	private int viewWidth;
	private int cellSize;
	private int cellRows = 8;
	private int cellColumns = 8;
	private Paint lines = new Paint();
	private Paint[] colorsPieces = new Paint[4];

	public BoardGame(Context c) {
		super(c);
		init();
	}

	public BoardGame(Context c, AttributeSet as) {
		super(c, as);
		init();
	}

	public BoardGame(Context c, AttributeSet as, int default_style) {
		super(c, as, default_style);
		init();
	}

	private void init() {
		lines.setStyle(Paint.Style.FILL_AND_STROKE);
		lines.setColor(Color.BLACK);

		colorsPieces[0] = new Paint();
		colorsPieces[1] = new Paint();
		colorsPieces[2] = new Paint();
		colorsPieces[3] = new Paint();
		colorsPieces[0].setFlags(Paint.ANTI_ALIAS_FLAG);
		colorsPieces[1].setFlags(Paint.ANTI_ALIAS_FLAG);
		colorsPieces[2].setFlags(Paint.ANTI_ALIAS_FLAG);
		colorsPieces[0].setColor(ContextCompat.getColor(getContext(), R.color.pieceWhite));
		colorsPieces[1].setColor(ContextCompat.getColor(getContext(), R.color.pieceBlack));
		colorsPieces[2].setColor(ContextCompat.getColor(getContext(), R.color.pieceOption));
		colorsPieces[3].setColor(Color.TRANSPARENT);

		this.setOnTouchListener(new OnTouchListener() {
			@Override
			public boolean onTouch(View v, MotionEvent event) {
				if (event.getAction() == MotionEvent.ACTION_DOWN) {
					int x = (int) ((event.getX() * cellColumns) / viewWidth);
					int y = (int) ((event.getY() * cellRows) / viewHeight);
					if (gameEngine.action(x, y, getContext())) {
						checkWin();
						mainActivity.updateScores(gameEngine.scores);
						mainActivity.changePlayer(gameEngine.currentPlayer);
						invalidate();
					}
				}
				return true;
			}
		});
	}

	public void reset() {
		for (int y = 0; y < cellRows; ++y) {
			for (int x = 0; x < cellColumns; ++x) {
				if ((x == 3 && y == 3) || (x == 4 && y == 4))
					gameEngine.pieces[y][x] = new Piece((x * cellSize) + cellSize / 2, (y * cellSize) + cellSize / 2, Piece.WHITE);
				else if ((x == 3 && y == 4) || (x == 4 && y == 3))
					gameEngine.pieces[y][x] = new Piece((x * cellSize) + cellSize / 2, (y * cellSize) + cellSize / 2, Piece.BLACK);
				else
					gameEngine.pieces[y][x] = new Piece((x * cellSize) + cellSize / 2, (y * cellSize) + cellSize / 2, Piece.EMPTY);
			}
		}
		gameEngine.reset();
		mainActivity.updateScores(gameEngine.scores);
		mainActivity.changePlayer(gameEngine.currentPlayer);
		invalidate();
	}

	private void checkWin() {
		if (gameEngine.noMoves < 2) {
			if (gameEngine.options == 0) {
				++gameEngine.noMoves;
				if (gameEngine.currentPlayer == Piece.BLACK)
					gameEngine.currentPlayer = Piece.WHITE;
				else
					gameEngine.currentPlayer = Piece.BLACK;
				gameEngine.checkOptions();
				checkWin();
			} else {
				gameEngine.noMoves = 0;
			}
		} else if (gameEngine.filled || gameEngine.noMoves == 2) {
			mainActivity.updateScores(gameEngine.scores);
			displayWinner();
		}
	}

	private void displayWinner() {
		String[] players = {getContext().getString(R.string.white), getContext().getString(R.string.black)};
		int winner = gameEngine.scores[Piece.WHITE] > gameEngine.scores[Piece.BLACK] ? Piece.WHITE : Piece.BLACK;
		AlertDialog.Builder builder = new AlertDialog.Builder(mainActivity);
		builder.setTitle(R.string.end_game).setMessage(
				players[winner] + " wins with a score of " + gameEngine.scores[winner]);
		builder.setPositiveButton(R.string.new_game, new DialogInterface.OnClickListener() {
			public void onClick(DialogInterface dialog, int id) {
				reset();
			}
		});
		builder.setNegativeButton(R.string.exit, new DialogInterface.OnClickListener() {
			public void onClick(DialogInterface dialog, int id) {
				mainActivity.finish();
			}
		});
		AlertDialog dialog = builder.create();
		dialog.setCancelable(false);
		dialog.setCanceledOnTouchOutside(false);
		dialog.show();
	}

	private void calcDimensionsVertical() {
		cellSize = viewWidth / cellColumns;
		viewHeight = viewWidth;
	}

	private void calcDimensionsHorizontal() {
		cellSize = viewHeight / cellRows;
		viewWidth = viewHeight;
	}

	private void calcPieces() {
		for (int y = 0; y < cellRows; ++y) {
			for (int x = 0; x < cellColumns; ++x) {
				if ((x == 3 && y == 3) || (x == 4 && y == 4))
					gameEngine.pieces[y][x] = new Piece((x * cellSize) + cellSize / 2, (y * cellSize) + cellSize / 2, Piece.WHITE);
				else if ((x == 3 && y == 4) || (x == 4 && y == 3))
					gameEngine.pieces[y][x] = new Piece((x * cellSize) + cellSize / 2, (y * cellSize) + cellSize / 2, Piece.BLACK);
				else
					gameEngine.pieces[y][x] = new Piece((x * cellSize) + cellSize / 2, (y * cellSize) + cellSize / 2, Piece.EMPTY);
			}
		}
		mainActivity.updateScores(gameEngine.scores);
		gameEngine.checkOptions();
	}

	@Override
	protected void onDraw(Canvas canvas) {
		super.onDraw(canvas);

		canvas.drawColor(ContextCompat.getColor(getContext(), R.color.boardColor));

		for (int i = 0; i < cellRows; i++) {
			canvas.drawLine(0, i * cellSize, cellSize * cellColumns, i * cellSize, lines);
		}

		for (int i = 0; i < cellColumns + 1; i++) {
			canvas.drawLine(i * cellSize, 0, i * cellSize, cellSize * cellRows, lines);
		}

		for (int y = 0; y < cellRows; ++y) {
			for (int x = 0; x < cellColumns; ++x) {
				Piece p = gameEngine.pieces[y][x];
				switch (p.type) {
					case Piece.EMPTY:
						break;
					case Piece.OPTION:
						canvas.drawCircle(p.x, p.y, (cellSize / 6), colorsPieces[p.type]);
						break;
					default:
						canvas.drawCircle(p.x, p.y, (cellSize / 3 + cellSize / 2) / 2, colorsPieces[p.type]);
				}
			}
		}

	}

	@Override
	protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
		viewWidth = MeasureSpec.getSize(widthMeasureSpec);
		viewHeight = MeasureSpec.getSize(heightMeasureSpec);

		if (viewHeight > viewWidth)
			calcDimensionsVertical();
		else
			calcDimensionsHorizontal();
		setMeasuredDimension(viewWidth, viewHeight);

		calcPieces();

		invalidate();
	}

	public void setMainActivity(MainActivity mainActivity) {
		this.mainActivity = mainActivity;
	}
}
