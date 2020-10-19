import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner lector = new Scanner(System.in);
        int widht, height;
        do {
            height = lector.nextInt();
            widht = lector.nextInt();
            lector.nextLine();
            if (widht > 0 || height > 0) {
                Robot robot = new Robot();
                Maze maze = new Maze(lector, widht, height);
                maze.fillMaze();
                robot.setInitPos(0, maze.getHEIGHT() - 1, maze);
                robot.move(maze);
                maze.countRepeticiones();
                for (int i = 0; i < maze.getRepeticiones().length; ++i) {
                    if (maze.getRepeticiones()[i]<= 9 ) System.out.print("  " + maze.getRepeticiones()[i]);
                    else if (maze.getRepeticiones()[i] <= 99) System.out.print(" " +maze.getRepeticiones()[i]);
                    else System.out.print(maze.getRepeticiones()[i]);
                }
                System.out.println();
            }
        } while (widht > 0 || height > 0);
    }
}

class Robot {
    private int[] pos;
    final private int[] finalPos;
    private String heading;

    public Robot() {
        pos = new int[2];
        finalPos = new int[2];
        heading = "right";
    }

    public void move(Maze maze) {
        while (pos[0] != finalPos[0] || pos[1] != finalPos[1]) {
            if (isWallOnRight(maze))
                switch (heading) {
                    case "right":
                        pos[0]++;
                        if (colisioning(maze)) {
                            pos[0]--;
                            turnLeft();
                            break;
                        }
                        maze.pos[pos[1]][pos[0]]++;
                        break;
                    case "left":
                        pos[0]--;
                        if (colisioning(maze)) {
                            pos[0]++;
                            turnLeft();
                            break;
                        }
                        maze.pos[pos[1]][pos[0]]++;
                        break;
                    case "up":
                        pos[1]--;
                        if (colisioning(maze)) {
                            pos[1]++;
                            turnLeft();
                            break;
                        }
                        maze.pos[pos[1]][pos[0]]++;
                        break;
                    case "down":
                        pos[1]++;
                        if (colisioning(maze)) {
                            pos[1]--;
                            turnLeft();
                            break;
                        }
                        maze.pos[pos[1]][pos[0]]++;
                        break;
                }
            else {
                turnRight();
                maze.pos[pos[1]][pos[0]]++;
            }
        }
    }

    public void setInitPos(int x, int y, Maze maze) {
        pos[0] = x + 1;
        pos[1] = y;
        finalPos[0] = x;
        finalPos[1] = y;
        maze.pos[pos[1]][pos[0]]++;

    }

    public boolean colisioning(Maze maze) {
        return pos[0] == maze.getWIDTH() || pos[1] == maze.getHEIGHT() || pos[0] == -1 || pos[1] == -1 || maze.getPosValue(pos[0], pos[1]) == -1;
    }

    public void turnLeft() {
        switch (heading) {
            case "right":
                heading = "up";
                break;
            case "left":
                heading = "down";
                break;
            case "up":
                heading = "left";
                break;
            case "down":
                heading = "right";
                break;
        }
    }

    public void turnRight() {
        switch (heading) {
            case "right":
                heading = "down";
                pos[1]++;
                break;
            case "left":
                heading = "up";
                pos[1]--;
                break;
            case "up":
                heading = "right";
                pos[0]++;
                break;
            case "down":
                heading = "left";
                pos[0]--;
                break;
        }
    }

    public boolean isWallOnRight(Maze maze) {
        switch (heading) {
            case "right":
                if (pos[1] + 1 == maze.getHEIGHT() || maze.getPosValue(pos[0], pos[1] + 1) == -1)
                    return true;
                break;
            case "left":
                if (pos[1] - 1 == -1 || maze.getPosValue(pos[0], pos[1] - 1) == -1)
                    return true;
                break;
            case "up":
                if (pos[0] + 1 == maze.getWIDTH() || maze.getPosValue(pos[0] + 1, pos[1]) == -1)
                    return true;
                break;
            case "down":
                if (pos[0] - 1 == -1 || maze.getPosValue(pos[0] - 1, pos[1]) == -1)
                    return true;
                break;
        }
        return false;
    }

}

class Maze {
    protected final int[][] pos;
    final private Scanner lector;
    final private int WIDTH;
    final private int HEIGHT;
    private final int[] repeticiones;

    public Maze(Scanner lector, int width, int height) {
        this.lector = lector;
        WIDTH = width;
        HEIGHT = height;
        pos = new int[height][width];
        repeticiones = new int[5];
    }

    public void fillMaze() {
        for (int i = 0; i < HEIGHT; ++i) {
            String line = lector.nextLine();
            for (int j = 0; j < WIDTH; j++) {
                pos[i][j] = Integer.parseInt(String.valueOf(line.charAt(j))) == 1 ? -1 : 0;
            }

        }
    }

    public void countRepeticiones() {
        for (int[] i : pos) {
            for (int j : i) {
                if (j != -1) {
                    repeticiones[j]++;
                }
            }
        }
    }

    public int getPosValue(int x, int y) {
        return pos[y][x];
    }

    public int getHEIGHT() {
        return HEIGHT;
    }

    public int getWIDTH() {
        return WIDTH;
    }

    public int[] getRepeticiones() {
        return repeticiones;
    }
}