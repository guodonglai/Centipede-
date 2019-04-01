import java.awt.Color;
import java.awt.geom.Rectangle2D;


public class ShotgunShell extends Instance {
	
	private static final int BULLET_SPEED = 10;
	private final Color BULLET_COLOR = Color.GRAY;
	private final int BULLET_SIZE = 15;
	private final int NUMBER_OF_BULLETS = 5;
	private final int BULLET_TIME = 25;
	
	private int angle;
	private int timer;
	
	public ShotgunShell(int bulletNum, int x, int y, CentipedeComponent comp){
		super(x, y, comp);
		this.angle = 60 + bulletNum*(60/NUMBER_OF_BULLETS);
		this.timer = 0;
	}
	
	@Override
	public void update(){
		if(this.timer == BULLET_TIME){
			this.die();
		}
		this.timer ++;
		this.x += BULLET_SPEED*Math.cos(Math.toRadians(this.angle));
		this.y -= BULLET_SPEED*Math.sin(Math.toRadians(this.angle));
		this.sprite = new Rectangle2D.Double(this.x, this.y, BULLET_SIZE, BULLET_SIZE);
	}
	
	@Override
	public Color getColor(){
		return BULLET_COLOR;
	}
	
	@Override
	public void collide(Collidable collidable) {
		collidable.collideWithShotgunShell(this);
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
