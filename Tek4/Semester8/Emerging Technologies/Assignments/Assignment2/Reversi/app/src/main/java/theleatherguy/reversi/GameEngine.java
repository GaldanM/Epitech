package theleatherguy.reversi;

import android.content.Context;
import android.widget.Toast;

import java.util.LinkedList;

public class GameEngine {
	private static final int NW = 0;
	private static final int N = 1;
	private static final int NE = 2;
	private static final int W = 3;
	private static final int E = 4;
	private static final int SW = 5;
	private static final int S = 6;
	private static final int SE = 7;

	public boolean filled = true;
	public int noMoves = 0;
	public int options = 0;
	public Piece[][] pieces;
	public int[] scores;
	public int currentPlayer;

	private GameEngine() {
		currentPlayer = Piece.BLACK;
		pieces = new Piece[8][8];
		scores = new int[2];
	}

	public void reset() {
		currentPlayer = Piece.BLACK;
		filled = true;
		noMoves = 0;
		options = 0;
		cleanOptions();
		checkOptions();
	}

	public void countScores() {
		scores[Piece.WHITE] = 0;
		scores[Piece.BLACK] = 0;
		for (int y = 0; y < 8; ++y)
			for (int x = 0; x < 8; ++x) {
				Piece p = pieces[y][x];
				if (p.type == Piece.WHITE || p.type == Piece.BLACK)
					scores[p.type] += 1;
			}
	}

	public boolean action(int x, int y, Context c) {
		Piece opt = pieces[y][x];
		if (opt.type == Piece.OPTION) {
			for (LinkedList<Piece> list : opt.options) {
				for (Piece p : list) {
					p.type = currentPlayer;
				}
			}
			filled = true;
			cleanOptions();
			opt.type = currentPlayer;
			if (currentPlayer == Piece.BLACK)
				currentPlayer = Piece.WHITE;
			else
				currentPlayer = Piece.BLACK;
			checkOptions();
			return true;
		}
		return false;
	}

	public void cleanOptions() {
		for (int y = 0; y < 8; ++y) {
			for (int x = 0; x < 8; ++x) {
				Piece p = pieces[y][x];

				if (p.type == Piece.OPTION) {
					p.type = Piece.EMPTY;
					for (int i = 0; i < 8; ++i)
						p.options.get(i).clear();
				}
			}
		}
	}

	public void checkOptions() {
		boolean atLeastOne;
		options = 0;

		for (int y = 0; y < 8; ++y) {
			for (int x = 0; x < 8; ++x) {
				Piece p = pieces[y][x];

				if ((p.type == Piece.EMPTY || p.type == Piece.OPTION)) {
					atLeastOne = checkOptions(x - 1, y - 1, NW, p);
					atLeastOne |= checkOptions(x, y - 1, N, p);
					atLeastOne |= checkOptions(x + 1, y - 1, NE, p);
					atLeastOne |= checkOptions(x - 1, y, W, p);
					atLeastOne |= checkOptions(x + 1, y, E, p);
					atLeastOne |= checkOptions(x - 1, y + 1, SW, p);
					atLeastOne |= checkOptions(x, y + 1, S, p);
					atLeastOne |= checkOptions(x + 1, y + 1, SE, p);
					if (atLeastOne) {
						p.type = Piece.OPTION;
						++options;
					}
					filled = false;
				}
			}
		}
	}

	private boolean checkOptions(int x, int y, int direction, Piece root) {
		boolean ret;
		switch (direction) {
			case NW:
				if (x - 1 >= 0 && y - 1 >= 0) {
					LinkedList<Piece> list = root.options.get(direction);
					Piece p = pieces[y][x];
					if (p.type == Piece.EMPTY || p.type == Piece.OPTION) {
						return false;
					} else if (p.type == currentPlayer) {
						return !list.isEmpty();
					} else {
						list.add(p);
						ret = checkOptions(x - 1, y - 1, direction, root);
						if (!ret)
							list.clear();
						return ret;
					}
				} else
					return false;
			case N:
				if (y - 1 >= 0) {
					LinkedList<Piece> list = root.options.get(direction);
					Piece p = pieces[y][x];
					if (p.type == Piece.EMPTY || p.type == Piece.OPTION) {
						return false;
					} else if (p.type == currentPlayer) {
						return !list.isEmpty();
					} else {
						list.add(p);
						ret = checkOptions(x, y - 1, direction, root);
						if (!ret)
							list.clear();
						return ret;
					}
				} else
					return false;
			case NE:
				if (x + 1 < 8 && y - 1 >= 0) {
					LinkedList<Piece> list = root.options.get(direction);
					Piece p = pieces[y][x];
					if (p.type == Piece.EMPTY || p.type == Piece.OPTION) {
						return false;
					} else if (p.type == currentPlayer) {
						return !list.isEmpty();
					} else {
						list.add(p);
						ret = checkOptions(x + 1, y - 1, direction, root);
						if (!ret)
							list.clear();
						return ret;
					}
				} else
					return false;
			case W:
				if (x - 1 >= 0) {
					LinkedList<Piece> list = root.options.get(direction);
					Piece p = pieces[y][x];
					if (p.type == Piece.EMPTY || p.type == Piece.OPTION) {
						return false;
					} else if (p.type == currentPlayer) {
						return !list.isEmpty();
					} else {
						list.add(p);
						ret = checkOptions(x - 1, y, direction, root);
						if (!ret)
							list.clear();
						return ret;
					}
				} else
					return false;
			case E:
				if (x + 1 < 8) {
					LinkedList<Piece> list = root.options.get(direction);
					Piece p = pieces[y][x];
					if (p.type == Piece.EMPTY || p.type == Piece.OPTION) {
						return false;
					} else if (p.type == currentPlayer) {
						return !list.isEmpty();
					} else {
						list.add(p);
						ret = checkOptions(x + 1, y, direction, root);
						if (!ret)
							list.clear();
						return ret;
					}
				} else
					return false;
			case SW:
				if (x - 1 >= 0 && y + 1 < 8) {
					LinkedList<Piece> list = root.options.get(direction);
					Piece p = pieces[y][x];
					if (p.type == Piece.EMPTY || p.type == Piece.OPTION) {
						return false;
					} else if (p.type == currentPlayer) {
						return !list.isEmpty();
					} else {
						list.add(p);
						ret = checkOptions(x - 1, y + 1, direction, root);
						if (!ret)
							list.clear();
						return ret;
					}
				} else
					return false;
			case S:
				if (y + 1 < 8) {
					LinkedList<Piece> list = root.options.get(direction);
					Piece p = pieces[y][x];
					if (p.type == Piece.EMPTY || p.type == Piece.OPTION) {
						return false;
					} else if (p.type == currentPlayer) {
						return !list.isEmpty();
					} else {
						list.add(p);
						ret = checkOptions(x, y + 1, direction, root);
						if (!ret)
							list.clear();
						return ret;
					}
				} else
					return false;
			case SE:
				if (x + 1 < 8 && y + 1 < 8) {
					LinkedList<Piece> list = root.options.get(direction);
					Piece p = pieces[y][x];
					if (p.type == Piece.EMPTY || p.type == Piece.OPTION) {
						return false;
					} else if (p.type == currentPlayer) {
						return !list.isEmpty();
					} else {
						list.add(p);
						ret = checkOptions(x + 1, y + 1, direction, root);
						if (!ret)
							list.clear();
						return ret;
					}
				} else
					return false;
		}
		return true;
	}

	private static GameEngine INSTANCE = new GameEngine();

	public static synchronized GameEngine getInstance() {
		if (INSTANCE == null) {
			INSTANCE = new GameEngine();
		}
		return INSTANCE;
	}
}
