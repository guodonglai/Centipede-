import javax.swing.JFrame;

/**
 * The main class for your arcade game.
 * 
 * You can design your game any way you like, but make the game start
 * by running main here.
 * 
 * Also don't forget to write javadocs for your classes and functions!
 * 
 * @author Buffalo
 *
 */
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println("Write your cool arcade game here!");
		JFrame frame = new JFrame("Centipede");
		
		CentipedeComponent game = new CentipedeComponent();
		game.setFocusable(true);
		game.requestFocusInWindow();
		frame.add(game);
		Thread thread = new Thread(game);
		thread.start();
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.pack();
		frame.setVisible(true);
	}

}
