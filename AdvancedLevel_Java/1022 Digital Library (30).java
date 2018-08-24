import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.TreeSet;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in), 6 * 1024 * 1024);

    static class Library {
        HashMap<String, TreeSet<String>>[] allMaps = new HashMap[5];

        Library() throws IOException {
            for (int i = 0; i < 5; i++) {
                HashMap<String, TreeSet<String>> map = new HashMap<>(1000, 1);
                allMaps[i] = map;
            }
            int record_size = Integer.valueOf(reader.readLine());
            for (int i = 0; i < record_size; i++) {
                String id = reader.readLine();
                for (int j = 0; j < allMaps.length; j++) {
                    HashMap<String, TreeSet<String>> map = allMaps[j];
                    if (j == 2) {
                        String[] keys = reader.readLine().split(" ");
                        for (String key : keys) {
                            putValue(map, key, id);
                        }
                    } else {
                        String key = reader.readLine();
                        putValue(map, key, id);
                    }
                }
            }
        }

        TreeSet<String> query(int id, String queryString) {
            HashMap<String, TreeSet<String>> allMap = allMaps[id - 1];
            TreeSet<String> integers = allMap.get(queryString);
            return integers;
        }

        private void putValue(HashMap<String, TreeSet<String>> map, String key, String id) {
            TreeSet<String> integers = map.computeIfAbsent(key, k -> new TreeSet<>());
            integers.add(id);
        }
    }

    public static void main(String[] args) throws IOException {
        Library library = new Library();
        int query_size = Integer.valueOf(reader.readLine());
        for (int i = 0; i < query_size; i++) {
            String line = reader.readLine();
            System.out.println(line);
            int id = line.charAt(0) - 48;
            String query = line.substring(3);
            TreeSet<String> queryResult = library.query(id, query);
            if (queryResult == null) {
                System.out.println("Not Found");
            } else {
                for (String book_id : queryResult) {
                    System.out.println(book_id);
                }
            }
        }
    }
}