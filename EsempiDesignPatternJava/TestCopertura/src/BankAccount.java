
public class BankAccount {
	private boolean premium = false;
	private double credit;
	
	public BankAccount() {
		credit=0.0;
	}
	
	public BankAccount(double init) {
		deposit(init);
	}
	
	public void deposit(double amount) {
		if (amount >= 1000) premium = true;
		
		if (premium) amount += amount * 0.05;
		
		credit += amount;
	}
	
	public double withdraw(double amount) {
		double cash = 0.0;
		
		if (premium || credit - amount >= 0) {
			credit -= amount;
			cash = amount;
		} else {
			cash=credit;
			credit=0;
		}
		
		return cash;
	}
	
	public boolean isPremium() {
		return premium;
	}
	
	public double getCredit() {
		return credit;
	}
}
