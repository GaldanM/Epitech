package UltimateTicTacToe;

import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.scene.transform.Translate;

class XOBoard extends Pane {
    private int[][] board;
    private XOPiece[][] renders;

    private Rectangle back;
    private Line h1, h2, v1, v2;
    private double cell_width, cell_height;
    private Translate ch_one, ch_two, cw_one, cw_two;

    private int move_count;
    private int lastY;
    private int lastX;
    private boolean full;
    private int winner;

    XOBoard() {
        this.full = false;
        this.winner = -1;
        this.move_count = 0;

        board = new int[3][3];
        renders = new XOPiece[3][3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                renders[i][j] = null;
            }

        back = new Rectangle();
        back.setFill(Color.WHITE);
        h1 = new Line();
        h2 = new Line();
        v1 = new Line();
        v2 = new Line();
        h1.setStroke(Color.BLACK);
        h2.setStroke(Color.BLACK);
        v1.setStroke(Color.BLACK);
        v2.setStroke(Color.BLACK);

        h1.setStartX(0);
        h1.setStartY(0);
        h1.setEndY(0);
        h2.setStartX(0);
        h2.setStartY(0);
        h2.setEndY(0);
        v1.setStartX(0);
        v1.setStartY(0);
        v1.setEndX(0);
        v2.setStartX(0);
        v2.setStartY(0);
        v2.setEndX(0);

        ch_one = new Translate(0, 0);
        ch_two = new Translate(0, 0);
        h1.getTransforms().add(ch_one);
        h2.getTransforms().add(ch_two);

        cw_one = new Translate(0, 0);
        cw_two = new Translate(0, 0);
        v1.getTransforms().add(cw_one);
        v2.getTransforms().add(cw_two);

        getChildren().addAll(back, h1, h2, v1, v2);
    }

    @Override
    public void resize(double width, double height) {
        super.resize(width, height);
        cell_width = width / 3.0;
        cell_height = height / 3.0;

        back.setWidth(width);
        back.setHeight(height);

        ch_one.setY(cell_height);
        ch_two.setY(2 * cell_height);
        h1.setEndX(width);
        h2.setEndX(width);

        cw_one.setX(cell_width);
        cw_two.setX(2 * cell_width);
        v1.setEndY(height);
        v2.setEndY(height);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 0) {
                    renders[i][j].relocate(i * cell_width, j * cell_height);
                    renders[i][j].resize(cell_width, cell_height);
                }
            }
        }
    }

    int getLastPlayedY() {
        return (this.lastY);
    }

    int getLastPlayedX() {
        return (this.lastX);
    }

    boolean isFull() {
        return (this.full);
    }

    int getWinner() {
        return (this.winner);
    }

    void reset() {
        this.full = false;
        this.winner = -1;
        this.move_count = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = 0;
                getChildren().remove(renders[i][j]);
                renders[i][j] = null;
            }
        }
        changeActive();
    }

    boolean placePiece(final double x, final double y, final int current_player) {
        int indexX = (int) (x / cell_width);
        int indexY = (int) (y / cell_height);

        if (board[indexX][indexY] == 0) {
            board[indexX][indexY] = current_player;
            renders[indexX][indexY] = new XOPiece(current_player);
            renders[indexX][indexY].resize(cell_width, cell_height);
            renders[indexX][indexY].relocate(indexX * cell_width, indexY * cell_height);

            getChildren().add(renders[indexX][indexY]);

            ++this.move_count;
            this.lastY = indexY;
            this.lastX = indexX;
            if (winner == -1)
                checkWin(indexX, indexY, board[indexX][indexY], current_player);
            if (this.move_count == 9) {
                this.full = true;
                if (winner == -1) {
                    winner = 0;
                }
            }
            return (true);
        }
        return (false);
    }

    void changeActive() {
        if (winner != -1) {
            switch (winner) {
                case 1:
                    back.setFill(Color.web("FFCDD2"));
                    break;
                case 2:
                    back.setFill(Color.web("C8E6C9"));
                    break;
            }
        } else {
            back.setFill(Color.WHITE);
        }
        h1.setStroke(Color.BLACK);
        h2.setStroke(Color.BLACK);
        v1.setStroke(Color.BLACK);
        v2.setStroke(Color.BLACK);
    }

    void changeInactive() {
        if (winner != -1) {
            switch (winner) {
                case 1:
                    back.setFill(Color.web("B71C1C"));
                    break;
                case 2:
                    back.setFill(Color.web("1B5E20"));
                    break;
            }
        } else {
            back.setFill(Color.BLACK);
        }
        h1.setStroke(Color.WHITE);
        h2.setStroke(Color.WHITE);
        v1.setStroke(Color.WHITE);
        v2.setStroke(Color.WHITE);
    }

    void changeFull() {
        switch (winner) {
            case 0:
                back.setFill(Color.web("01579B"));
                break;
            case 1:
                back.setFill(Color.web("B71C1C"));
                break;
            case 2:
                back.setFill(Color.web("1B5E20"));
                break;
        }
        h1.setStroke(Color.WHITE);
        h2.setStroke(Color.WHITE);
        v1.setStroke(Color.WHITE);
        v2.setStroke(Color.WHITE);
    }

    private void checkWin(final int x, final int y, final int s, final int player) {
        for (int i = 0; i < 3; i++) {
            if (board[x][i] != s)
                break;
            if (i == 3 - 1) {
                this.winner = player;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (board[i][y] != s)
                break;
            if (i == 2) {
                this.winner = player;
            }
        }

        if (x == y) {
            for (int i = 0; i < 3; i++) {
                if (board[i][i] != s)
                    break;
                if (i == 2) {
                    this.winner = player;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            if (board[i][2 - i] != s)
                break;
            if (i == 2) {
                this.winner = player;
            }
        }
    }
}
