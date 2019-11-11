
public class TestBank {
	
	public static void main(String[] args) {
		TestBank t=new TestBank();
		
		t.testVersamentoNormale(100);
		t.testPrelievoNormale(100);
		t.testUpgrade();
		t.testStartPremium();
		t.testVersamentoPremium();
		t.testPrelievoPremium();
	}
	
	public void testVersamentoNormale(double amount) {
		BankAccount normale=new BankAccount();
		
		normale.deposit(amount);
		if(normale.getCredit()==amount)
			System.out.println("testVersamentoNormale SI");
		else
			System.out.println("testVersamentoNormale NO");
	}
	
	public void testPrelievoNormale(double amount) {
		BankAccount normale=new BankAccount(amount);
		
		if(normale.withdraw(amount)==amount)
			System.out.println("testPrelievoNormale 1 SI");
		else
			System.out.println("testPrelievoNormale 1 NO");
		
		normale.deposit(amount-10);
		if(normale.withdraw(amount)==amount-10)
			System.out.println("testPrelievoNormale 2 SI");
		else
			System.out.println("testPrelievoNormale 2 NO");
		
	}
	
	public void testUpgrade() {
		BankAccount normale=new BankAccount();
		
		normale.deposit(1000);
		if(normale.isPremium())
			System.out.println("testUpgrade SI");
		else
			System.out.println("testUpgrade NO");
	}
	
	public void testStartPremium() {
		BankAccount premium=new BankAccount(1000);
		
		if(premium.isPremium())
			System.out.println("testStartPremium SI");
		else
			System.out.println("testStartPremium NO");	
	}
	
	public void testVersamentoPremium() {
		BankAccount premium=new BankAccount(1000);

		premium.withdraw(1050);
		premium.deposit(100);
		if(premium.getCredit()==105)
			System.out.println("testVersamentoPremium SI");
		else
			System.out.println("testVersamentoPremium NO");
	}
	 
	public void testPrelievoPremium() {
		BankAccount premium=new BankAccount(1000);
		
		if(premium.withdraw(200)==200)
			System.out.println("testPrelievoPremium 1 SI");
		else
			System.out.println("testPrelievoPremium 1 NO");
		
		if(premium.withdraw(5000)==5000 && premium.getCredit() < 0)
			System.out.println("testPrelievoPremium 2 SI");
		else
			System.out.println("testPrelievoPremium 2 NO");
		
	}
}
