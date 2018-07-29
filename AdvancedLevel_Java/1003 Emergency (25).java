import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.TreeSet;

public class Main {
    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    static class Road implements Comparable<Road> {
        int fromCity, toCity, distance;

        Road(int fromCity, int toCity, int distance) {
            this.fromCity = fromCity;
            this.toCity = toCity;
            this.distance = distance;
        }

        @Override
        public int compareTo(Road o) {
            int compare = distance - o.distance;
            if (compare == 0) {
                compare = toCity - o.toCity;
                return compare == 0 ? fromCity - o.fromCity : compare;
            } else {
                return compare;
            }
        }
    }

    static class Node implements Comparable<Node> {
        int id, rescueTeams = 0, roadLength = 0;

        Node(int id, int rescueTeams) {
            this.id = id;
            this.rescueTeams = rescueTeams;
        }

        @Override
        public int compareTo(Node o) {
            int compare = roadLength - o.roadLength;
            return compare == 0 ? hashCode() - o.hashCode() : compare;
        }

        @Override
        public String toString() {
            return "Node{" +
                    "id=" + id +
                    ", rescueTeams=" + rescueTeams +
                    ", roadLength=" + roadLength +
                    '}';
        }
    }

    static class CityMap {
        final int cityNumbers, start_city, end_city, roadNumbers;
        final int[] rescues;
        final LinkedList<Road>[] roads;

        CityMap() throws IOException {
            int[] ints = readLine();
            this.cityNumbers = ints[0];
            this.roadNumbers = ints[1];
            this.start_city = ints[2];
            this.end_city = ints[3];
            rescues = readLine();
            roads = new LinkedList[cityNumbers];
            for (int i = 0; i < cityNumbers; i++) {
                roads[i] = new LinkedList<>();
            }

            for (int i = 0; i < roadNumbers; i++) {
                //读入路径
                ints = readLine();
                int start = ints[0], end = ints[1], length = ints[2];
                roads[start].add(new Road(start, end, length));
                roads[end].add(new Road(end, start, length));
            }
        }
    }

    private static int[] readLine() throws IOException {
        return Arrays.stream(reader.readLine().split(" "))
                .mapToInt(Integer::valueOf)
                .toArray();
    }

    public static void main(String[] args) throws IOException {
        final CityMap cityMap = new CityMap();
        final int start_city = cityMap.start_city;
        final int end_city = cityMap.end_city;
        int[] rescues = cityMap.rescues;

        boolean[] visited = new boolean[cityMap.cityNumbers];
        TreeSet<Node> nodes = new TreeSet<>();
        nodes.add(new Node(start_city, rescues[start_city]));
        int max_counts = 0;
        int max_rescue_teams = 0;
        int min_load_length = Integer.MAX_VALUE;
        while (!nodes.isEmpty()) {
            Node node = nodes.pollFirst();
            visited[node.id] = true;
            if (node.roadLength > min_load_length) break;
            if (node.id == end_city) {
                min_load_length = node.roadLength;
                max_counts++;
                max_rescue_teams = Math.max(max_rescue_teams, node.rescueTeams);
            }
            for (Road road : cityMap.roads[node.id]) {
                if (!visited[road.toCity]) {
                    Node newNode = new Node(road.toCity, node.rescueTeams + rescues[road.toCity]);
                    newNode.roadLength = node.roadLength + road.distance;
                    nodes.add(newNode);
                }
            }
        }

        System.out.println(max_counts + " " + max_rescue_teams);
    }
}