
public interface Collidable {
	
	public void collide(Collidable collidable);
	
	public void collideWithMushroom(Mushroom m);
	
	public void collideWithCharacter(PlayerCharacter c);
	
	public void collideWithBullet(Bullet b);
	
	public void collideWithCentipede(LinkedCentipede c);
	
	public void collideWithShotgunShell(ShotgunShell s);
	
	public void collideWithBoomerang(Boomerang b);
	
	public void collideWithGunPickup(GunPickup g);
	
	public void collideWithSpider(Spider s);
	
	public void collideWithScorpion(Scorpion s);
	
	public void collideWithFlea(Flea f);

}
