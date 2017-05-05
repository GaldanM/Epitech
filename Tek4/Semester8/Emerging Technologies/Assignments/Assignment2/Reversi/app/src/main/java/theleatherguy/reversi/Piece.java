package theleatherguy.reversi;

import java.util.ArrayList;
import java.util.LinkedList;

public class Piece {
	static final int WHITE = 0;
	static final int BLACK = 1;
	static final int OPTION = 2;
	static final int EMPTY = 3;

	public float x;
	public float y;
	public int type;
	public ArrayList<LinkedList<Piece>> options;

	Piece(int x, int y, int type) {
		this.x = x;
		this.y = y;
		this.type = type;
		this.options = new ArrayList<>();
		for (int i = 0; i < 8; ++i)
			this.options.add(new LinkedList<Piece>());
	}
}
