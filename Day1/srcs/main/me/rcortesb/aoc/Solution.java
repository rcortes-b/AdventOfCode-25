package srcs.main.me.rcortesb.aoc;

import java.util.List;

public class Solution {
	final int dialStartingPoint = 50;
	final int leftLimit = 0;
	final int rightLimit = 99;
	private int dialPoint;
	private int pointZeroAtTheEnd;
	private int pointToZero;

	public Solution() {
		this.dialPoint = dialStartingPoint;
		this.pointZeroAtTheEnd = 0;
		this.pointToZero = 0;
	}

	public void run(List<String> content) {
		char c = '\0';
		int value = 0;
		for (String line : content) {
			c = line.charAt(0);
			value = Integer.valueOf(line.substring(1));
			if (value > rightLimit) {
				this.passByZero(value / 100);
				value = value % 100;
			}
			this.move(c, value);
			this.isZero();
		}
		this.showResolution();
	}

	private void move(char c, int value) {
		if (c == 'R')
			this.moveRight(value);
		else
			this.moveLeft(value);
	}

	private void isZero() {
		if (this.dialPoint == 0)
			this.pointZeroAtTheEnd += 1;
	}

	private void passByZero(int times) {
		this.pointToZero += times;
	}

	public void moveRight(int value) {
		final int tmp = dialPoint;
		dialPoint += value;
		if (dialPoint > rightLimit) {
			dialPoint -= 100;
			if (tmp != 0)
				this.passByZero(1);
		}
	}

	private void moveLeft(int value) {
		final int tmp = dialPoint;
		dialPoint -= value;
		if (dialPoint < leftLimit) {
			dialPoint = 100 + dialPoint;
			if (tmp != 0)
				this.passByZero(1);
		} else if (tmp != 0 && dialPoint == 0) {
			this.passByZero(1);
		}
	}

	private void showResolution() {
		System.out.println("Currently the dial poits to " + dialPoint);
		System.out.println("The dial has been zero " + pointZeroAtTheEnd + " times");
		System.out.println("The dial has passed by zero " + pointToZero + " times");
	}
}
