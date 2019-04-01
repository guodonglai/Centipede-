import java.awt.Color;
import java.awt.Image;
import java.awt.Toolkit;
import java.util.Random;


public class LinkedCentipede extends Instance {
	
	public static final int SPEED = 2;
	public static final Color CENTIPEDE_COLOR = Color.DARK_GRAY;
	public static final Color HEAD_COLOR = Color.ORANGE;
	public static final int HEAD_SIZE = 20;
	public static final int DEFAULT_X = 440;
	public static final int DEFAULT_Y = 20;
	public static final int MOVEMENT_SPEED = 20;
	public static final int BORDER = 20;
	public static final int SCREEN_SIZE = 900;
	
	private int movingDown;
	private int movingSide;
	private LinkedCentipede nextSegment;
	private int prevX;
	private int prevY;
	private int timer;
	private boolean sick;
	private boolean dead;
	private int spawnTimer;
	
	public LinkedCentipede(int x, int y, int nSegments, CentipedeComponent comp) {
		super(x, y, comp);
		this.timer = 0;
		this.prevX = x;
		this.prevY = y;
		this.movingDown = 1;
		this.movingSide = 1;
		this.sick = false;
		this.dead = false;
		this.spawnTimer = 0;
		if(nSegments > 1){
			this.nextSegment = new LinkedCentipede(x + 20, y, nSegments - 1, comp);
			this.comp.addInstance(this.nextSegment);
		}else{
			this.nextSegment = null;
		}
	}
	
	@Override
	public Image getImage(){
		if(this.nextSegment == null){
			return Toolkit.getDefaultToolkit().getImage("src/CentipedeHead.png");
		}
		return Toolkit.getDefaultToolkit().getImage("src/CentipedeBody.png");
	}
	
	public LinkedCentipede(int nSegments, CentipedeComponent component) {
		this(DEFAULT_X, DEFAULT_Y, nSegments, component);
	}
	
	public int getPrevX(){
		return this.prevX;
	}
	
	public int getPrevY(){
		return this.prevY;
	}
	
	public int getMovingSide(){
		return this.movingSide;
	}
	
	public void dropAndTurn(){
		this.prevX = this.x;
		this.prevY = this.y;
		this.movingSide *= -1;
		this.y += 20 * this.movingDown;
	}
	
	public void move(){
		this.prevY = this.y;
		this.prevX = this.x;
		if(this.x <= BORDER||this.x>=SCREEN_SIZE - BORDER){
			dropAndTurn();
		}
		if(this.y <= 0||this.y >= (SCREEN_SIZE - 2 * BORDER)){
			this.movingDown *= 0;
		}
		this.x += this.movingSide * MOVEMENT_SPEED;
	}
	
	public void changeNextSegment(LinkedCentipede c){
		this.nextSegment = c;
	}
	
//	@Override
//	public void die(){
//		if(this.nextSegment != null){
//			this.nextSegment.die();
//		}
//		this.comp.removeinstance(this);
//	}
	
	public boolean isDead(){
		return this.dead;
	}
	
	@Override
	public void update(){
		this.timer ++;
		if(this.movingDown == 0){
			this.spawnTimer ++;
			if(this.spawnTimer >= 180){
				this.spawnTimer = 0;
				Random rand = new Random();
				int newY = 900 - 20*rand.nextInt(4);
				int newX = 40 + 20*rand.nextInt(40);
				this.comp.addInstanceToAdd(new LinkedCentipede(newX, newY, 1, this.comp));
			}
		}
		if(this.nextSegment != null && this.nextSegment.isDead() == true){
			this.nextSegment = null;
		}
		if(this.timer > 20){
			if(this.nextSegment == null){
				if(!this.sick){
					this.move();
				}
				if(this.sick){
					this.prevY = this.y;
					this.prevX = this.x;
					this.y += MOVEMENT_SPEED;
				}
			}
			if(this.nextSegment != null){
				this.prevX = this.x;
				this.prevY = this.y;
				this.x = this.nextSegment.getPrevX();
				this.y = this.nextSegment.getPrevY();
			}
			if(this.y >= SCREEN_SIZE - 2*BORDER){
				this.sick = false;
			}
			this.timer = 0;
			if(this.x == this.prevX && this.y == this.prevY){
				this.die();
			}
		}
		super.update();
	}
	
	@Override
	public Color getColor(){
		if(this.nextSegment == null){
			return HEAD_COLOR;
		}
		return CENTIPEDE_COLOR;
	}
	
	@Override
	public String toString(){
		return "Centipede";
	}
	
	@Override
	public void collideWithMushroom(Mushroom m){
		if(!this.sick){
			if(m.getPoisonedStatus()){
				this.sick = true;
				this.y += 20;
			}
			else{
				dropAndTurn();
			}
		}
		else{
			m.die();
		}
	}
	
	public void breakSegment(){
		this.comp.getCharacter().addScore(15);
		comp.addInstanceToAdd(new Mushroom(this.prevX,this.prevY,comp));
		this.dead = true;
		if(this.nextSegment == null){
			this.die();
		}
		if(this.y<60){
			this.y += 20;
		}else{
			this.y -= 20;
		}
		this.movingSide *= -1;
		this.nextSegment = null;
	}
	
	@Override
	public void collideWithBullet(Bullet b){
		b.die();
		breakSegment();
	}
	
	@Override
	public void collideWithBoomerang(Boomerang b){
		b.die();
		breakSegment();
	}
	
	@Override
	public void collideWithShotgunShell(ShotgunShell s){
		s.die();
		breakSegment();
	}
	
	@Override
	public void collideWithCharacter(PlayerCharacter c){
		c.hitByEnemy();
	}


}
