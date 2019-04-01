import java.awt.Color;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.geom.Rectangle2D;
import java.io.IOException;
import java.util.HashMap;



public class PlayerCharacter extends Instance implements Moveable, Collidable{
	
	private final static Color HERO_COLOR = Color.BLUE;
	private final static int DEFAULT_X = 424;
	private final static int DEFAULT_Y = 800;
	private final int RELOAD_FRAMES = 20;
	private final int PISTOL_NUMBER = 1;
	private final int SHOTGUN_NUMBER = 2;
	private final int BOOMERANG_NUMBER = 3;
	private final int ANIMATION_TIME = 30;
	
	private boolean isFiring;
	private int timer;
	private int prevX;
	private int prevY;
	private int gunNumber;
	private int animationTimer;
	private int life;
	private int score;
	
	public PlayerCharacter(CentipedeComponent comp) {
		super(DEFAULT_X, DEFAULT_Y, comp);
		this.timer = RELOAD_FRAMES;
		this.gunNumber = PISTOL_NUMBER;
		this.animationTimer = 0;
		this.life = 3;
		this.score = 0;
	}
	
	public void readMap(HashMap<Integer, Boolean> hashMap) {
		this.prevX = this.x;
		this.prevY = this.y;
		if(hashMap.get(38) && this.y > 600){
			super.moveUp();
		}
		if(hashMap.get(39) && this.x < 880){
			super.moveRight();
		}
		if(hashMap.get(40) && this.y < 880){
			super.moveDown();
		}
		if(hashMap.get(37) && this.x > 0){
			super.moveLeft();
		}
		this.isFiring = hashMap.get(32);
	}
	
	public int getLives(){
		return this.life;
	}
	
	public void hitByEnemy(){
		if(this.life > 0){
			this.life --;
			this.x = DEFAULT_X;
			this.y = DEFAULT_Y;
		}
		else{
			System.out.println("YOU DIED");
			try {
				this.comp.loadLevel(this.comp.getLevelNum());
			} catch (IOException exception) {
				// WILL LOAD A LEVEL
				exception.printStackTrace();
			}
		}
	}
	
	public int getScore(){
		return this.score;
	}
	
	public void addScore(int i){
		score += i;
	}
	
	@Override
	public Color getColor(){
		return HERO_COLOR;
	}
	
	public int getGunID(){
		return this.gunNumber;
	}
	
	@Override
	public Image getImage(){
		if(this.animationTimer >= ANIMATION_TIME/2){
			return Toolkit.getDefaultToolkit().getImage("src/Player1.png");
		}
		return Toolkit.getDefaultToolkit().getImage("src/Player2.png");
	}
	
	public boolean getFiring(){
		if(this.timer > RELOAD_FRAMES && this.isFiring){
			this.timer = 0;
			return true;
		}
		return false;
	}
	
	public void addTimer(){
		if(this.timer <= RELOAD_FRAMES){
			this.timer += 1;
		}
	}
	
	@Override
	public void update(){
		this.animationTimer ++;
		if(this.animationTimer >= ANIMATION_TIME){
			this.animationTimer = 0;
		}
		this.sprite = new Rectangle2D.Double(this.x, this.y, 20, 20);
	}
	
	public void stop(){
		this.x = prevX;
		this.y = prevY;
	}

	@Override
	public void collide(Collidable collidable) {
		collidable.collideWithCharacter(this);
		
	}

	@Override
	public void collideWithMushroom(Mushroom m) {
		System.out.println("BOOP");
		
	}

	@Override
	public void collideWithCharacter(PlayerCharacter c) {
		// Only one instance of character
		
	}

	@Override
	public void collideWithBullet(Bullet b) {
		// Cannot shoot self
		
	}
	
	@Override
	public void collideWithCentipede(LinkedCentipede c){
		System.out.println("YOU DIED");
	}
	
	public int getGunNumber(){
		return this.gunNumber;
	}
	
	public void changeGun(int gunNum){
		this.gunNumber = gunNum;
	}
}
