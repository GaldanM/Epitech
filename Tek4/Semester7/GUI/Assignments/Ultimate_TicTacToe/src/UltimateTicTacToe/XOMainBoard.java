package UltimateTicTacToe;

import javafx.scene.control.Alert;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.scene.transform.Translate;

class XOMainBoard extends Pane {
    private XOBoard[][] boards;

    private int current_player;
    private XOBoard current_board;
    private int move_count;

    private Line h1, h2, v1, v2;
    private Translate ch_one, ch_two, cw_one, cw_two;
    private double cell_width, cell_height;

    private final int XPLAYER = 1;
    private final int OPLAYER = 2;

    XOMainBoard() {
        boards = new XOBoard[3][3];

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                boards[i][j] = new XOBoard();
                getChildren().add(boards[i][j]);
            }
        }

        current_player = XPLAYER;
        move_count = 0;

        h1 = new Line();
        h2 = new Line();
        v1 = new Line();
        v2 = new Line();
        h1.setStroke(Color.RED);
        h2.setStroke(Color.RED);
        v1.setStroke(Color.RED);
        v2.setStroke(Color.RED);

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

        getChildren().addAll(h1, h2, v1, v2);
    }

    @Override
    public void resize(double width, double height) {
        super.resize(width, height);

        cell_width = width / 3.0;
        cell_height = height / 3.0;

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
                boards[i][j].relocate(i * cell_width, j * cell_height);
                boards[i][j].resize(cell_width, cell_height);
            }
        }
    }

    void resetGame() {
        move_count = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                boards[i][j].reset();
            }
        }
    }

    void placePiece(final double x, final double y) {
        int indexX = (int) (x / cell_width);
        int indexY = (int) (y / cell_height);
        XOBoard boardPlayed = boards[indexX][indexY];

        if (move_count == 0 || current_board.isFull())
            current_board = boardPlayed;
        if (current_board == boardPlayed) {
            if (current_board.placePiece(x - (indexX * cell_width), y - (indexY * cell_height), current_player)) {
                current_player = current_player == XPLAYER ? OPLAYER : XPLAYER;
                current_board = boards[current_board.getLastPlayedX()][current_board.getLastPlayedY()];
                ++move_count;
                checkWin();
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (boards[i][j] == current_board && !current_board.isFull())
                            boards[i][j].changeActive();
                        else if (current_board.isFull()) {
                            if (boards[i][j].isFull())
                                boards[i][j].changeFull();
                            else
                                boards[i][j].changeActive();
                        } else {
                            if (boards[i][j].isFull())
                                boards[i][j].changeFull();
                            else
                                boards[i][j].changeInactive();
                        }
                    }
                }
            }
        }
    }

    private void checkWin() {
        int XWins = 0;
        int OWins = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int winner = boards[i][j].getWinner();
                if (winner == OPLAYER)
                    ++OWins;
                else if (winner == XPLAYER)
                    ++XWins;
            }
        }
        if (move_count == 81) {
            String piece;
            if (OWins > XWins)
                piece = "Circles";
            else if (XWins > OWins)
                piece = "Crosses";
            else
                piece = "Nobody";

            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Game finished");
            alert.setHeaderText(piece + " has won this game :\n" +
                    "Circles : " + OWins + "\n" +
                    "Crosses : " + XWins + "\n" +
                    "Draws : " + Math.abs(OWins - XWins));
            alert.showAndWait();

            this.resetGame();
        }
    }
}
