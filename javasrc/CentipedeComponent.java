import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.geom.Rectangle2D;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;

import javax.swing.JOptionPane;
import javax.swing.JPanel;


public class CentipedeComponent extends JPanel implements Runnable {
	
	private final int BLOCK_SIZE = 25;
	private final int WINDOW_SIZE = 900;
	private final Color NORMAL_MUSHROOM_COLOR = Color.GREEN;
	private final Color POISONED_MUSHROOM_COLOR = Color.MAGENTA;
	private final Color HERO_COLOR = Color.BLUE;
	private final Color BULLET_COLOR = Color.GRAY;
	private final int PISTOL_NUMBER = 1;
	private final int SHOTGUN_NUMBER = 2;
	private final int BOOMERANG_NUMBER = 3;
	
	private int currentLevel;
	private ArrayList<Instance> instances;
	private ArrayList<Instance> instancestoremove;
	private ArrayList<Instance> instancesToAdd;
	private PlayerCharacter hero;
	private CentipedeListener gameListener;
	private int centipedeCount;
	private int mushroomCount;
	private int fleaTimer;
	private int enemySpawnTimer;
	private BackGroundMusicPlayer player;
	boolean IsPaused;
	private int weaponTimer;
	
	public CentipedeComponent(){
		setBackground(Color.WHITE);
		this.centipedeCount = 1;
		this.mushroomCount = 1;
		this.weaponTimer = 0;
		this.player = new BackGroundMusicPlayer ();
		this.setPreferredSize(new Dimension(this.WINDOW_SIZE, this.WINDOW_SIZE));
		
		int option = JOptionPane.showOptionDialog(this, "Welcome to Centipede!", "Centipede", JOptionPane.YES_NO_OPTION, 
				JOptionPane.PLAIN_MESSAGE, null, new String[] {"Start", "Exit"}, "a");
		if (option == 1) {
			System.exit(0);
		}

		this.instances = new ArrayList<Instance>();
		
		this.currentLevel = 0;
		try {
			loadLevel(this.currentLevel);
		} catch (IOException ex) {
			// IO EXCEPTION
		}
		
		this.gameListener = new CentipedeListener(this);
		this.addKeyListener(this.gameListener);
	}
	
	public int getLevelNum(){
		return this.currentLevel;
	}
	
	public PlayerCharacter getCharacter(){
		return this.hero;
	}

	public void loadLevel(int levelNum) throws IOException {
		// Load sample level
		this.currentLevel = levelNum;
		this.centipedeCount = 1;
		this.mushroomCount = 1;
		this.instances = new ArrayList<Instance>();
		this.instances.add(new LinkedCentipede(15, this));
		this.instancestoremove = new ArrayList<Instance>();
		this.instancesToAdd = new ArrayList<Instance>();
		this.hero = new PlayerCharacter(this);
		this.instances.add(this.hero);	
		this.fleaTimer = 0;
		this.enemySpawnTimer = 0;
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader("src/level"+levelNum+".txt"));
		} catch (FileNotFoundException exception) {
			// FILE NOT FOUND
		}
		try {
		    StringBuilder sb = new StringBuilder();
		    String line = br.readLine();
		    int yGrid = 0;
		    while (line != null) {
		    	yGrid ++;
		        sb.append(line);
		        sb.append(System.lineSeparator());
		        line = br.readLine();
		    }
		    String everything = sb.toString();
		    String[] lines = everything.split(System.getProperty("line.separator"));
		    int scanX = 0;
		    int scanY = 0;
		    for(String currentLine: lines){
		    	scanY += 20;
		    	scanX = 0;
		    	for(int i = 0; i<currentLine.length(); i++){
		    		scanX += 20;
		    		if(currentLine.charAt(i) == 'M'){
		    			this.instances.add(new Mushroom(scanX, scanY,this));
		    		}
		    		if(currentLine.charAt(i) == 'S'){
		    			this.instances.add(new GunPickup(this.SHOTGUN_NUMBER, scanX, scanY, this));
		    		}
		    		if(currentLine.charAt(i) == 'P'){
		    			this.instances.add(new GunPickup(this.PISTOL_NUMBER, scanX, scanY, this));
		    		}
		    		if(currentLine.charAt(i) == 'B'){
		    			this.instances.add(new GunPickup(this.BOOMERANG_NUMBER, scanX, scanY, this));
		    		}
		    	}
		    }
		} finally {
		    br.close();
		}
	}
	
	public void addInstanceToAdd(Instance instance){
		this.instancesToAdd.add(instance);
	}
	
	public void addInstance(Instance instance){
		
		this.instances.add(instance);
	}
	
	private void addSquare(Graphics2D g2, Rectangle2D.Double sprite, Color color){
		// ADD A SQUARE
		g2.setColor(color);		
		g2.fill(sprite);
	}
	
	private void addImage(Graphics g2, Image img, int x, int y){
		g2.drawImage(img, x, y, this);
	}
	
	void removeinstance(Instance in){
		this.instancestoremove.add(in);
	}

	@Override
	public void run() {
		try{
			while (true){
				if(!this.IsPaused){
					this.updateInstances();
					
				}
				this.repaint();
				//Thread.sleep((long) 100);
				Thread.sleep((long) 16.666667);
			}
		}
		catch (InterruptedException ex){
			// Interrupted
		}
	}
	
	public void updateInstances(){
		for(Instance y:this.instancestoremove){
			this.instances.remove(y);
		}
		for(Instance toAdd: this.instancesToAdd){
			this.instances.add(toAdd);
		}
		this.instancesToAdd = new ArrayList<Instance>();
		this.instancestoremove=new ArrayList<Instance>();
		this.hero.readMap(this.gameListener.getHashMap());
		this.hero.addTimer();
		if(this.hero.getFiring()){
			if(this.hero.getGunNumber() == this.PISTOL_NUMBER){
				this.instances.add(new Bullet(this.hero.getX()+5, this.hero.getY(),this));
			}
			if(this.hero.getGunNumber() == this.SHOTGUN_NUMBER){
				for(int i=0; i<6; i++){
					this.instances.add(new ShotgunShell(i, this.hero.getX()+5, this.hero.getY(), this));
				}
			}
			if(this.hero.getGunNumber() == this.BOOMERANG_NUMBER){
				this.instances.add(new Boomerang(this.hero, this.hero.getX() + 5, this.hero.getY() - 1, this));
			}
		}
		this.hero.update();
		this.centipedeCount = 0;
		this.mushroomCount = 0;
		for(Instance instance: this.instances){
			instance.update();
			if(this.hero.getSprite().intersects(instance.getSprite())){
				this.hero.collide(instance);
				//this.hero.update();
			}
			if(instance.toString().equals("Centipede")){
				this.centipedeCount ++;
			}
			if(instance.toString().equals("Mushroom") && instance.isInPlayerArea()){
				this.mushroomCount ++;
			}
			for(Instance some:this.instances){
				if(instance.getSprite().intersects(some.getSprite())){
					instance.collide(some);
				}
			}
		}
		if(this.centipedeCount == 0){
			System.out.println("YOU WON!");
			this.hero.addScore(100);
			int nextLevel = 0;
			if(this.currentLevel == 2){
				nextLevel = 0;
			}
			else{
				nextLevel = this.currentLevel + 1;
			}
			try {
				loadLevel(nextLevel);
			} catch (IOException exception) {
				// TODO Auto-generated catch-block stub.
				exception.printStackTrace();
			}
		}
		this.enemySpawnTimer ++;
		if(this.enemySpawnTimer >= 300){
			this.enemySpawnTimer = 0;
			Random rand = new Random();
			int newX = 40 + 20*rand.nextInt(40);
			int newY = 40 + 20*rand.nextInt(30);
			if(rand.nextBoolean()){
				newY = 600 + 20*rand.nextInt(14);
				this.instancesToAdd.add(new Spider(newX, newY, this));
			}
			else{
				this.instancesToAdd.add(new Scorpion(newX, newY, this));
			}
			int weaponX = 40 + 20*rand.nextInt(40);
			int weaponY = 600 + 20*rand.nextInt(14);
			this.instancesToAdd.add(new GunPickup(rand.nextInt(2) + 1, weaponX, weaponY, this));
		}
		if(this.mushroomCount <= 5){
			if(this.fleaTimer < 180){
				this.fleaTimer ++;
			}
			if(this.fleaTimer >= 180){
				// DO NOTHING: Flea's are not properly responding, and causing massive
				// amounts of lag
				Random rand = new Random();
				int dist = rand.nextInt(40);
				this.instancesToAdd.add(new Flea(40 + 20*dist, 40, this));
				this.fleaTimer = 0;
			}
			
		}
	}

	
	@Override
	protected void paintComponent(Graphics g){
		super.paintComponent(g);
		Graphics2D g2 = (Graphics2D) g;
		addSquare(g2, this.hero.getSprite(), this.hero.getColor());
		for(Instance instance: this.instances){
			addSquare(g2, instance.getSprite(), instance.getColor());
			if(instance.getImage() != null){
				addImage(g2, instance.getImage(), instance.getX(), instance.getY());
			}
		}
		g2.setColor(Color.RED);
		g2.setFont(new Font("Ariel", Font.PLAIN, 30));
		g2.drawString("Lives: " + this.hero.getLives() +
				"      Score: " + this.hero.getScore(), 20, 880);
		if (this.IsPaused) {
			Rectangle2D.Double ground = new Rectangle2D.Double(900 / 2, 900/ 2, 135, 40);
			g2.setColor(Color.BLACK);
			g2.fill(ground);
			g2.setColor(Color.white);
			g2.draw(ground);
			String paused = "Paused";
			g2.setFont(new Font("Consolas", Font.ITALIC, 40));
			g2.drawString(paused, 900/ 2+2, 900 / 2+30);
		}
	}
		
	

	/**
	 * TODO Put here a description of what this method does.
	 *
	 * @param b
	 */
	
	public void setIsPaused(boolean isPaused) {
		this.IsPaused = isPaused;
		this.player.pause(this.IsPaused);
	}
	
}
