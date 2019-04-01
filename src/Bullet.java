import java.awt.Color;
import java.awt.geom.Rectangle2D;


public class Bullet extends Instance implements Collidable{
	
	private static final int BULLET_SPEED = 10;
	private final Color BULLET_COLOR = Color.GRAY;
	private final int BULLET_SIZE = 15;


	public Bullet(int x, int y,CentipedeComponent comp) {
		super(x, y, comp);
	}
	
	@Override
	public void update(){
		this.y -= BULLET_SPEED;
		this.sprite = new Rectangle2D.Double(this.x, this.y, BULLET_SIZE, BULLET_SIZE);
	}

	@Override
	public Color getColor(){
		return this.BULLET_COLOR;
	}

	@Override
	public void collide(Collidable collidable) {
		collidable.collideWithBullet(this);
	}

	@Override
	public void collideWithMushroom(Mushroom m) {	
	}

	@Override
	public void collideWithCharacter(PlayerCharacter c) {
		// Cannot shoot self
		
	}

	@Override
	public void collideWithBullet(Bullet b) {
		// Bullets cannot collide with each other
		
	}
	
	@Override
	public void collideWithSpider(Spider s){
		s.die();
		this.die();
	}
	
	@Override
	public void collideWithScorpion(Scorpion s){
		s.die();
		this.die();
	}
	
	@Override
	public void collideWithFlea(Flea f){
		f.die();
		this.die();
	}

}
