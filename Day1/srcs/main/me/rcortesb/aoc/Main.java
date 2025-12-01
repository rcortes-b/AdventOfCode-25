package srcs.main.me.rcortesb.aoc;

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	final static String mapPath = "map.txt";
	final static String mapExamplePath = "map_example.txt";
	public static void main(String[] args) {
		List<String> mapExampleContent = getMapContent(mapExamplePath);
		List<String> mapContent = getMapContent(mapPath);
		
		Solution exampleSolution = new Solution();
		Solution mySolution = new Solution();

		exampleSolution.run(mapExampleContent);
		System.out.print("\n");
		mySolution.run(mapContent);
	}

	private static List<String> getMapContent(String mapPath) {
		File myFile = new File(mapPath);
		List<String> content = new ArrayList<>();
		try (Scanner scanner = new Scanner(myFile)) {
			while (scanner.hasNextLine()) {
				content.add(scanner.nextLine());
			}
		} catch (Exception e) {
			System.out.println("Problem with the file");
		}
		return content;
	}
}
