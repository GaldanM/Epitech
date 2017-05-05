import javafx.scene.control.Alert;

import java.util.ArrayList;
import java.util.LinkedList;

class GameLogic {
    private Board board;
    private Cell[][] cells;

    private final int EMPTY = 0;
    private final int WHITE = 1;
    private final int BLACK = 2;

    private final int NOTHING = 0;
    private final int SELECTED = 1;
    private final int SELECTABLE = 2;
    private final int MOVABLE = 3;
    private final int ATTACKABLE = 4;

    private int currentPlayer = BLACK;

    int[] scores = {
            0,
            14,
            14
    };

    private LinkedList<Cell> selected;
    private LinkedList<Cell> actions;

    GameLogic(Board board) {
        this.board = board;
        this.cells = board.cells;
        this.selected = new LinkedList<>();
        this.actions = new LinkedList<>();
    }

    private void listEmpty(Cell cell) {
        if (cell.type == currentPlayer) {
            cell.setStroke(SELECTED);
            this.selected.add(cell);
            this.checkActionSingle(this.selected.get(0));
        }
    }

    private void listOne(Cell cell) {
        if (this.actions.contains(cell)) {
            switch (cell.stroke) {
                case SELECTABLE:
                    this.clearActions();
                    cell.setStroke(SELECTED);
                    this.selected.add(cell);
                    this.checkActionMultiple(this.selected.get(0), 2);
                    this.checkActionMultiple(this.selected.get(1), 2);
                    break;

                case MOVABLE:
                    this.move(cell);
                    break;
            }
        } else if (this.selected.contains(cell)) {
            clearActions();
            cell.setStroke(NOTHING);
            this.selected.remove(cell);
        }
    }

    private void listTwo(Cell cell) {
        if (this.actions.contains(cell)) {
            switch (cell.stroke) {

                case SELECTABLE:
                    this.clearActions();
                    cell.setStroke(SELECTED);
                    this.selected.add(cell);
                    this.checkActionMultiple(this.selected.get(0), 3);
                    this.checkActionMultiple(this.selected.get(1), 3);
                    this.checkActionMultiple(this.selected.get(2), 3);
                    break;

                case MOVABLE:
                    this.move(cell);
                    break;

                case ATTACKABLE:
                    this.attack(cell);
                    break;
            }
        } else if (this.selected.contains(cell)) {
            clearActions();
            cell.setStroke(NOTHING);
            this.selected.remove(cell);
            this.checkActionSingle(this.selected.get(0));
        }
    }

    private void listThree(Cell cell) {
        if (this.actions.contains(cell)) {
            switch (cell.stroke) {
                case MOVABLE:
                    this.move(cell);
                    break;

                case ATTACKABLE:
                    this.attack(cell);
                    break;
            }
        } else if (this.selected.contains(cell)) {
            clearActions();
            cell.setStroke(NOTHING);
            this.selected.remove(cell);
            this.checkActionMultiple(this.selected.get(0), 2);
            this.checkActionMultiple(this.selected.get(1), 2);
        }
    }

    private void checkActionSingle(Cell cell) {
        ArrayList<Cell> arrayCell = new ArrayList<>();
        arrayCell.add(board.getCellFromZ1(cell.y - 1, cell.z1));
        arrayCell.add(board.getCellFromZ1(cell.y - 1, cell.z1 + 1));
        arrayCell.add(board.getCellFromZ1(cell.y, cell.z1 - 1));
        arrayCell.add(board.getCellFromZ1(cell.y, cell.z1 + 1));
        arrayCell.add(board.getCellFromZ1(cell.y + 1, cell.z1 - 1));
        arrayCell.add(board.getCellFromZ1(cell.y + 1, cell.z1));

        for (Cell adj : arrayCell) {
            if (adj != null) {
                if (adj.type == cell.type) {
                    adj.setStroke(SELECTABLE);
                    this.actions.add(adj);
                } else if (adj.type == EMPTY) {
                    adj.setStroke(MOVABLE);
                    this.actions.add(adj);
                }
            }
        }
    }

    private void checkActionMultiple(Cell cell, int size) {
        ArrayList<Cell> arrayCell = new ArrayList<>();
        arrayCell.add(board.getCellFromZ1(cell.y - 1, cell.z1));
        arrayCell.add(board.getCellFromZ1(cell.y - 1, cell.z1 + 1));
        arrayCell.add(board.getCellFromZ1(cell.y, cell.z1 - 1));
        arrayCell.add(board.getCellFromZ1(cell.y, cell.z1 + 1));
        arrayCell.add(board.getCellFromZ1(cell.y + 1, cell.z1 - 1));
        arrayCell.add(board.getCellFromZ1(cell.y + 1, cell.z1));


        for (Cell adj : arrayCell) {
            if (adj != null) {
                if ((adj.z1 == selected.get(0).z1 && adj.z1 == selected.get(1).z1)
                        || (adj.z2 == selected.get(0).z2 && adj.z2 == selected.get(1).z2)
                        || (adj.y == selected.get(0).y && adj.y == selected.get(1).y)) {
                    if (adj.type == cell.type && adj.stroke != SELECTED && size == 2) {
                        adj.setStroke(SELECTABLE);
                        this.actions.add(adj);
                    } else if (adj.type == EMPTY) {
                        adj.setStroke(MOVABLE);
                        this.actions.add(adj);
                    } else if (adj.type != cell.type) {
                        /*
                                     O X
                                    X X X
                                     X X
                        */
                        if (adj.y < selected.get(0).y
                                && selected.get(0).z1 == selected.get(1).z1) {
                            if (size == 2
                                    && (board.getCellFromZ1(adj.y - 1, adj.z1) == null
                                    || board.getCellFromZ1(adj.y - 1, adj.z1).type == EMPTY)) {
                                adj.setStroke(ATTACKABLE);
                                this.actions.add(adj);
                            } else if (size == 3
                                    && ((board.getCellFromZ1(adj.y - 1, adj.z1) == null
                                    || board.getCellFromZ1(adj.y - 1, adj.z1).type == EMPTY)
                                    || (board.getCellFromZ1(adj.y - 2, adj.z1) == null
                                    || board.getCellFromZ1(adj.y - 2, adj.z1).type == EMPTY))) {
                                adj.setStroke(ATTACKABLE);
                                this.actions.add(adj);
                            }
                        }

                        /*
                                     X O
                                    X X X
                                     X X
                        */
                        else if (adj.y < selected.get(0).y
                                && selected.get(0).z2 == selected.get(1).z2) {
                            if (size == 2
                                    && (board.getCellFromZ2(adj.y - 1, adj.z2) == null
                                    || board.getCellFromZ2(adj.y - 1, adj.z2).type == EMPTY)) {
                                adj.setStroke(ATTACKABLE);
                                this.actions.add(adj);
                            } else if (size == 3
                                    && ((board.getCellFromZ2(adj.y - 1, adj.z2) == null
                                    || board.getCellFromZ2(adj.y - 1, adj.z2).type == EMPTY)
                                    || (board.getCellFromZ2(adj.y - 2, adj.z2) == null
                                    || board.getCellFromZ2(adj.y - 2, adj.z2).type == EMPTY))) {
                                adj.setStroke(ATTACKABLE);
                                this.actions.add(adj);
                            }
                        }

                        /*
                                     X X
                                    O X X
                                     X X
                        */
                        else if (adj.x < selected.get(0).x) {
                            if (size == 2
                                    && (adj.x - 1 < 0
                                    || cells[adj.y][adj.x - 1].type == EMPTY)) {
                                adj.setStroke(ATTACKABLE);
                                this.actions.add(adj);
                            } else if (size == 3
                                    && ((adj.x - 1 < 0
                                    || cells[adj.y][adj.x - 1].type == EMPTY)
                                    || adj.x - 2 < 0
                                    || cells[adj.y][adj.x - 2].type == EMPTY)) {
                                adj.setStroke(ATTACKABLE);
                                this.actions.add(adj);
                            }
                        }

                        /*
                                     X X
                                    X X O
                                     X X
                        */
                        else if (adj.x > selected.get(0).x) {
                            if (size == 2
                                    && (adj.x + 1 >= cells[adj.y].length
                                    || cells[adj.y][adj.x + 1].type == EMPTY)) {
                                adj.setStroke(ATTACKABLE);
                                this.actions.add(adj);
                            } else if (size == 3
                                    && ((adj.x + 1 >= cells[adj.y].length
                                    || cells[adj.y][adj.x + 1].type == EMPTY)
                                    || (adj.x + 2) >= cells[adj.y].length
                                    || cells[adj.y][adj.x + 2].type == EMPTY)) {
                                adj.setStroke(ATTACKABLE);
                                this.actions.add(adj);
                            }
                        }

                        /*
                                     X X
                                    X X X
                                     X O
                        */
                        else if (adj.y > selected.get(0).y
                                && selected.get(0).z1 == selected.get(1).z1) {
                            if (size == 2
                                    && (board.getCellFromZ1(adj.y + 1, adj.z1) == null
                                    || board.getCellFromZ1(adj.y + 1, adj.z1).type == EMPTY)) {
                                adj.setStroke(ATTACKABLE);
                                this.actions.add(adj);
                            } else if (size == 3
                                    && ((board.getCellFromZ1(adj.y + 1, adj.z1) == null
                                    || board.getCellFromZ1(adj.y + 1, adj.z1).type == EMPTY)
                                    || (board.getCellFromZ1(adj.y + 2, adj.z1) == null
                                    || board.getCellFromZ1(adj.y + 2, adj.z1).type == EMPTY))) {
                                adj.setStroke(ATTACKABLE);
                                this.actions.add(adj);
                            }
                        }

                        /*
                                     X X
                                    X X X
                                     O X
                        */
                        else if (adj.y > selected.get(0).y
                                && selected.get(0).z2 == selected.get(1).z2) {
                            if (size == 2
                                    && (board.getCellFromZ2(adj.y + 1, adj.z2) == null
                                    || board.getCellFromZ2(adj.y + 1, adj.z2).type == EMPTY)) {
                                adj.setStroke(ATTACKABLE);
                                this.actions.add(adj);
                            } else if (size == 3
                                    && ((board.getCellFromZ2(adj.y + 1, adj.z2) == null
                                    || board.getCellFromZ2(adj.y + 1, adj.z2).type == EMPTY)
                                    || (board.getCellFromZ2(adj.y + 2, adj.z2) == null
                                    || board.getCellFromZ2(adj.y + 2, adj.z2).type == EMPTY))) {
                                adj.setStroke(ATTACKABLE);
                                this.actions.add(adj);
                            }
                        }
                    }
                }
            }
        }

    }

    private void attack(Cell attacked) {
        int size = this.selected.size();

        /*
                 O X
                X X X
                 X X
        */

        if (attacked.y < selected.get(0).y && selected.get(0).z1 == selected.get(1).z1) {
            Cell cellOne = board.getCellFromZ1(attacked.y - 1, attacked.z1);
            Cell cellTwo = board.getCellFromZ1(attacked.y - 2, attacked.z1);
            if (cellOne == null) {
                this.scores[attacked.type] -= 1;
                attacked.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ1(attacked.y + 3, attacked.z1).setType(EMPTY);
                } else {
                    board.getCellFromZ1(attacked.y + 2, attacked.z1).setType(EMPTY);
                }
            } else if (cellOne.type == EMPTY) {
                cellOne.setType(attacked.type);
                attacked.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ1(attacked.y + 3, attacked.z1).setType(EMPTY);
                } else {
                    board.getCellFromZ1(attacked.y + 2, attacked.z1).setType(EMPTY);
                }
            }
            if (cellTwo == null && cellOne != null) {
                this.scores[attacked.type] -= 1;
                attacked.setType(this.currentPlayer);
                board.getCellFromZ1(attacked.y + 3, attacked.z1).setType(EMPTY);
            } else if (cellTwo != null && cellTwo.type == EMPTY && cellOne != null && cellOne.type != EMPTY) {
                cellOne.setType(attacked.type);
                cellTwo.setType(attacked.type);
                attacked.setType(this.currentPlayer);
                board.getCellFromZ1(attacked.y + 3, attacked.z1).setType(EMPTY);
            }
        }

        /*
                 X O
                X X X
                 X X
        */

        else if (attacked.y < selected.get(0).y && selected.get(0).z2 == selected.get(1).z2) {
            Cell cellOne = board.getCellFromZ2(attacked.y - 1, attacked.z2);
            Cell cellTwo = board.getCellFromZ2(attacked.y - 2, attacked.z2);
            if (cellOne == null) {
                this.scores[attacked.type] -= 1;
                attacked.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ2(attacked.y + 3, attacked.z2).setType(EMPTY);
                } else {
                    board.getCellFromZ2(attacked.y + 2, attacked.z2).setType(EMPTY);
                }
            } else if (cellOne.type == EMPTY) {
                cellOne.setType(attacked.type);
                attacked.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ2(attacked.y + 3, attacked.z2).setType(EMPTY);
                } else {
                    board.getCellFromZ2(attacked.y + 2, attacked.z2).setType(EMPTY);
                }
            }
            if (cellTwo == null && cellOne != null) {
                this.scores[attacked.type] -= 1;
                attacked.setType(this.currentPlayer);
                board.getCellFromZ2(attacked.y + 3, attacked.z2).setType(EMPTY);
            } else if (cellTwo != null && cellTwo.type == EMPTY && cellOne != null && cellOne.type != EMPTY) {
                cellOne.setType(attacked.type);
                cellTwo.setType(attacked.type);
                attacked.setType(this.currentPlayer);
                board.getCellFromZ2(attacked.y + 3, attacked.z2).setType(EMPTY);
            }
        }
//
//                        /*
//                                     X X
//                                    X X X
//                                     X O
//                        */

        else if (attacked.y > selected.get(0).y && selected.get(0).z1 == selected.get(1).z1) {
            Cell cellOne = board.getCellFromZ1(attacked.y + 1, attacked.z1);
            Cell cellTwo = board.getCellFromZ1(attacked.y + 2, attacked.z1);
            if (cellOne == null) {
                this.scores[attacked.type] -= 1;
                attacked.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ1(attacked.y - 3, attacked.z1).setType(EMPTY);
                } else {
                    board.getCellFromZ1(attacked.y - 2, attacked.z1).setType(EMPTY);
                }
            } else if (cellOne.type == EMPTY) {
                cellOne.setType(attacked.type);
                attacked.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ1(attacked.y - 3, attacked.z1).setType(EMPTY);
                } else {
                    board.getCellFromZ1(attacked.y - 2, attacked.z1).setType(EMPTY);
                }
            }
            if (cellTwo == null && cellOne != null) {
                this.scores[attacked.type] -= 1;
                attacked.setType(this.currentPlayer);
                board.getCellFromZ1(attacked.y - 3, attacked.z1).setType(EMPTY);
            } else if (cellTwo != null && cellTwo.type == EMPTY && cellOne != null && cellOne.type != EMPTY) {
                cellOne.setType(attacked.type);
                cellTwo.setType(attacked.type);
                attacked.setType(this.currentPlayer);
                board.getCellFromZ1(attacked.y - 3, attacked.z1).setType(EMPTY);
            }
        }
//
//                        /*
//                                     X X
//                                    X X X
//                                     O X
//                        */
        else if (attacked.y > selected.get(0).y && selected.get(0).z2 == selected.get(1).z2) {
            Cell cellOne = board.getCellFromZ2(attacked.y + 1, attacked.z2);
            Cell cellTwo = board.getCellFromZ2(attacked.y + 2, attacked.z2);
            if (cellOne == null) {
                this.scores[attacked.type] -= 1;
                attacked.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ2(attacked.y - 3, attacked.z2).setType(EMPTY);
                } else {
                    board.getCellFromZ2(attacked.y - 2, attacked.z2).setType(EMPTY);
                }
            } else if (cellOne.type == EMPTY) {
                cellOne.setType(attacked.type);
                attacked.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ2(attacked.y - 3, attacked.z2).setType(EMPTY);
                } else {
                    board.getCellFromZ2(attacked.y - 2, attacked.z2).setType(EMPTY);
                }
            }
            if (cellTwo == null && cellOne != null) {
                this.scores[attacked.type] -= 1;
                attacked.setType(this.currentPlayer);
                board.getCellFromZ2(attacked.y - 3, attacked.z2).setType(EMPTY);
            } else if (cellTwo != null && cellTwo.type == EMPTY && cellOne != null && cellOne.type != EMPTY) {
                cellOne.setType(attacked.type);
                cellTwo.setType(attacked.type);
                attacked.setType(this.currentPlayer);
                board.getCellFromZ2(attacked.y - 3, attacked.z2).setType(EMPTY);
            }
        }

        //
//                        /*
//                                     X X
//                                    O X X
//                                     X X
//                        */

        else if (attacked.x < selected.get(0).x) {
            Cell cellOne = attacked.x - 1 < 0 ? this.cells[attacked.y][attacked.x - 1] : null;
            Cell cellTwo = attacked.x - 2 < 0 ? this.cells[attacked.y][attacked.x - 2] : null;
            if (cellOne == null) {
                this.scores[attacked.type] -= 1;
                attacked.setType(this.currentPlayer);
                if (size == 3) {
                    this.cells[attacked.y][attacked.x + 3].setType(EMPTY);
                } else {
                    this.cells[attacked.y][attacked.x + 2].setType(EMPTY);
                }
            } else if (cellOne.type == EMPTY) {
                cellOne.setType(attacked.type);
                attacked.setType(this.currentPlayer);
                if (size == 3) {
                    this.cells[attacked.y][attacked.x + 3].setType(EMPTY);
                } else {
                    this.cells[attacked.y][attacked.x + 2].setType(EMPTY);
                }
            }
            if (cellTwo == null && cellOne != null) {
                this.scores[attacked.type] -= 1;
                attacked.setType(this.currentPlayer);
                this.cells[attacked.y][attacked.x + 3].setType(EMPTY);
            } else if (cellTwo != null && cellTwo.type == EMPTY && cellOne != null && cellOne.type != EMPTY) {
                cellOne.setType(attacked.type);
                cellTwo.setType(attacked.type);
                attacked.setType(this.currentPlayer);
                this.cells[attacked.y][attacked.x + 3].setType(EMPTY);
            }
        }
//
//                        /*
//                                     X X
//                                    X X O
//                                     X X
//                        */
        else if (attacked.x > selected.get(0).x) {
            Cell cellOne = attacked.x + 1 < 0 ? this.cells[attacked.y][attacked.x + 1] : null;
            Cell cellTwo = attacked.x + 2 < 0 ? this.cells[attacked.y][attacked.x + 2] : null;
            if (cellOne == null) {
                this.scores[attacked.type] -= 1;
                attacked.setType(this.currentPlayer);
                if (size == 3) {
                    this.cells[attacked.y][attacked.x - 3].setType(EMPTY);
                } else {
                    this.cells[attacked.y][attacked.x - 2].setType(EMPTY);
                }
            } else if (cellOne.type == EMPTY) {
                cellOne.setType(attacked.type);
                attacked.setType(this.currentPlayer);
                if (size == 3) {
                    this.cells[attacked.y][attacked.x - 3].setType(EMPTY);
                } else {
                    this.cells[attacked.y][attacked.x - 2].setType(EMPTY);
                }
            }
            if (cellTwo == null && cellOne != null) {
                this.scores[attacked.type] -= 1;
                attacked.setType(this.currentPlayer);
                this.cells[attacked.y][attacked.x - 3].setType(EMPTY);
            } else if (cellTwo != null && cellTwo.type == EMPTY && cellOne != null && cellOne.type != EMPTY) {
                cellOne.setType(attacked.type);
                cellTwo.setType(attacked.type);
                attacked.setType(this.currentPlayer);
                this.cells[attacked.y][attacked.x - 3].setType(EMPTY);
            }
        }

        nextTurn();
    }

    private void move(Cell toMove) { // TODO : C'est un copié collé de attack, il faut encore faire la logique du move mais c'est pré-mâché normalement :)
        int size = this.selected.size();

        /*
                 O X
                X X X
                 X X
        */

        if (toMove.y < selected.get(0).y && selected.get(0).z1 == selected.get(1).z1) {
            Cell cellOne = board.getCellFromZ1(toMove.y - 1, toMove.z1);
            Cell cellTwo = board.getCellFromZ1(toMove.y - 2, toMove.z1);
            if (cellOne == null) {
                toMove.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ1(toMove.y + 3, toMove.z1).setType(EMPTY);
                } else {
                    board.getCellFromZ1(toMove.y + 2, toMove.z1).setType(EMPTY);
                }
            } else if (cellOne.type == EMPTY) {
                cellOne.setType(toMove.type);
                toMove.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ1(toMove.y + 3, toMove.z1).setType(EMPTY);
                } else {
                    board.getCellFromZ1(toMove.y + 2, toMove.z1).setType(EMPTY);
                }
            }
            if (cellTwo == null && cellOne != null) {
                toMove.setType(this.currentPlayer);
                board.getCellFromZ1(toMove.y + 3, toMove.z1).setType(EMPTY);
            } else if (cellTwo != null && cellTwo.type == EMPTY && cellOne != null && cellOne.type != EMPTY) {
                cellOne.setType(toMove.type);
                cellTwo.setType(toMove.type);
                toMove.setType(this.currentPlayer);
                board.getCellFromZ1(toMove.y + 3, toMove.z1).setType(EMPTY);
            }
        }

        /*
                 X O
                X X X
                 X X
        */

        else if (toMove.y < selected.get(0).y && selected.get(0).z2 == selected.get(1).z2) {
            Cell cellOne = board.getCellFromZ2(toMove.y - 1, toMove.z2);
            Cell cellTwo = board.getCellFromZ2(toMove.y - 2, toMove.z2);
            if (cellOne == null) {
                toMove.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ2(toMove.y + 3, toMove.z2).setType(EMPTY);
                } else {
                    board.getCellFromZ2(toMove.y + 2, toMove.z2).setType(EMPTY);
                }
            } else if (cellOne.type == EMPTY) {
                cellOne.setType(toMove.type);
                toMove.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ2(toMove.y + 3, toMove.z2).setType(EMPTY);
                } else {
                    board.getCellFromZ2(toMove.y + 2, toMove.z2).setType(EMPTY);
                }
            }
            if (cellTwo == null && cellOne != null) {
                toMove.setType(this.currentPlayer);
                board.getCellFromZ2(toMove.y + 3, toMove.z2).setType(EMPTY);
            } else if (cellTwo != null && cellTwo.type == EMPTY && cellOne != null && cellOne.type != EMPTY) {
                cellOne.setType(toMove.type);
                cellTwo.setType(toMove.type);
                toMove.setType(this.currentPlayer);
                board.getCellFromZ2(toMove.y + 3, toMove.z2).setType(EMPTY);
            }
        }
//
//                        /*
//                                     X X
//                                    X X X
//                                     X O
//                        */

        else if (toMove.y > selected.get(0).y && selected.get(0).z1 == selected.get(1).z1) {
            Cell cellOne = board.getCellFromZ1(toMove.y + 1, toMove.z1);
            Cell cellTwo = board.getCellFromZ1(toMove.y + 2, toMove.z1);
            if (cellOne == null) {
                toMove.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ1(toMove.y - 3, toMove.z1).setType(EMPTY);
                } else {
                    board.getCellFromZ1(toMove.y - 2, toMove.z1).setType(EMPTY);
                }
            } else if (cellOne.type == EMPTY) {
                cellOne.setType(toMove.type);
                toMove.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ1(toMove.y - 3, toMove.z1).setType(EMPTY);
                } else {
                    board.getCellFromZ1(toMove.y - 2, toMove.z1).setType(EMPTY);
                }
            }
            if (cellTwo == null && cellOne != null) {
                toMove.setType(this.currentPlayer);
                board.getCellFromZ1(toMove.y - 3, toMove.z1).setType(EMPTY);
            } else if (cellTwo != null && cellTwo.type == EMPTY && cellOne != null && cellOne.type != EMPTY) {
                cellOne.setType(toMove.type);
                cellTwo.setType(toMove.type);
                toMove.setType(this.currentPlayer);
                board.getCellFromZ1(toMove.y - 3, toMove.z1).setType(EMPTY);
            }
        }
//
//                        /*
//                                     X X
//                                    X X X
//                                     O X
//                        */
        else if (toMove.y > selected.get(0).y && selected.get(0).z2 == selected.get(1).z2) {
            Cell cellOne = board.getCellFromZ2(toMove.y + 1, toMove.z2);
            Cell cellTwo = board.getCellFromZ2(toMove.y + 2, toMove.z2);
            if (cellOne == null) {
                toMove.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ2(toMove.y - 3, toMove.z2).setType(EMPTY);
                } else {
                    board.getCellFromZ2(toMove.y - 2, toMove.z2).setType(EMPTY);
                }
            } else if (cellOne.type == EMPTY) {
                cellOne.setType(toMove.type);
                toMove.setType(this.currentPlayer);
                if (size == 3) {
                    board.getCellFromZ2(toMove.y - 3, toMove.z2).setType(EMPTY);
                } else {
                    board.getCellFromZ2(toMove.y - 2, toMove.z2).setType(EMPTY);
                }
            }
            if (cellTwo == null && cellOne != null) {
                toMove.setType(this.currentPlayer);
                board.getCellFromZ2(toMove.y - 3, toMove.z2).setType(EMPTY);
            } else if (cellTwo != null && cellTwo.type == EMPTY && cellOne != null && cellOne.type != EMPTY) {
                cellOne.setType(toMove.type);
                cellTwo.setType(toMove.type);
                toMove.setType(this.currentPlayer);
                board.getCellFromZ2(toMove.y - 3, toMove.z2).setType(EMPTY);
            }
        }

        //
//                        /*
//                                     X X
//                                    O X X
//                                     X X
//                        */

        else if (toMove.x < selected.get(0).x) {
            Cell cellOne = toMove.x - 1 < 0 ? this.cells[toMove.y][toMove.x - 1] : null;
            Cell cellTwo = toMove.x - 2 < 0 ? this.cells[toMove.y][toMove.x - 2] : null;
            if (cellOne == null) {
                toMove.setType(this.currentPlayer);
                if (size == 3) {
                    this.cells[toMove.y][toMove.x + 3].setType(EMPTY);
                } else {
                    this.cells[toMove.y][toMove.x + 2].setType(EMPTY);
                }
            } else if (cellOne.type == EMPTY) {
                cellOne.setType(toMove.type);
                toMove.setType(this.currentPlayer);
                if (size == 3) {
                    this.cells[toMove.y][toMove.x + 3].setType(EMPTY);
                } else {
                    this.cells[toMove.y][toMove.x + 2].setType(EMPTY);
                }
            }
            if (cellTwo == null && cellOne != null) {
                toMove.setType(this.currentPlayer);
                this.cells[toMove.y][toMove.x + 3].setType(EMPTY);
            } else if (cellTwo != null && cellTwo.type == EMPTY && cellOne != null && cellOne.type != EMPTY) {
                cellOne.setType(toMove.type);
                cellTwo.setType(toMove.type);
                toMove.setType(this.currentPlayer);
                this.cells[toMove.y][toMove.x + 3].setType(EMPTY);
            }
        }
//
//                        /*
//                                     X X
//                                    X X O
//                                     X X
//                        */
        else if (toMove.x > selected.get(0).x) {
            Cell cellOne = toMove.x + 1 < 0 ? this.cells[toMove.y][toMove.x + 1] : null;
            Cell cellTwo = toMove.x + 2 < 0 ? this.cells[toMove.y][toMove.x + 2] : null;
            if (cellOne == null) {
                toMove.setType(this.currentPlayer);
                if (size == 3) {
                    this.cells[toMove.y][toMove.x - 3].setType(EMPTY);
                } else {
                    this.cells[toMove.y][toMove.x - 2].setType(EMPTY);
                }
            } else if (cellOne.type == EMPTY) {
                cellOne.setType(toMove.type);
                toMove.setType(this.currentPlayer);
                if (size == 3) {
                    this.cells[toMove.y][toMove.x - 3].setType(EMPTY);
                } else {
                    this.cells[toMove.y][toMove.x - 2].setType(EMPTY);
                }
            }
            if (cellTwo == null && cellOne != null) {
                toMove.setType(this.currentPlayer);
                this.cells[toMove.y][toMove.x - 3].setType(EMPTY);
            } else if (cellTwo != null && cellTwo.type == EMPTY && cellOne != null && cellOne.type != EMPTY) {
                cellOne.setType(toMove.type);
                cellTwo.setType(toMove.type);
                toMove.setType(this.currentPlayer);
                this.cells[toMove.y][toMove.x - 3].setType(EMPTY);
            }
        }

        nextTurn();
    }


    private void clearActions() {
        for (Cell cell : actions)
            cell.setStroke(NOTHING);
        this.actions.clear();
    }

    private void clearSelected() {
        for (Cell cell : selected)
            cell.setStroke(NOTHING);
        this.selected.clear();
    }

    private void nextTurn() {
        this.clearActions();
        this.clearSelected();
        this.currentPlayer = this.currentPlayer % 2 + 1;
        this.board.setNextPlayer(this.currentPlayer);
        this.board.updateScores();
        if (this.scores[BLACK] == 0 || this.scores[WHITE] == 0) {
            String winner = this.scores[BLACK] == 0 ? "WHITE" : "BLACK";
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Game finished");
            alert.setHeaderText(winner + " has won this game !!");
            alert.showAndWait();

            this.board.reset();
        }
    }

    void currentMove(int y, int x) {
        Cell cell = cells[y][x];
        switch (this.selected.size()) {
            case 0:
                listEmpty(cell);
                break;
            case 1:
                listOne(cell);
                break;
            case 2:
                listTwo(cell);
                break;
            case 3:
                listThree(cell);
                break;
        }
    }

    void reset() {
        this.clearActions();
        this.clearSelected();
        this.scores[EMPTY] = 0;
        this.scores[WHITE] = 14;
        this.scores[BLACK] = 14;
        this.cells = this.board.cells;
        currentPlayer = BLACK;
        this.board.setNextPlayer(BLACK);
    }

    int getCurrentPlayer() {
        return this.currentPlayer;
    }
}
