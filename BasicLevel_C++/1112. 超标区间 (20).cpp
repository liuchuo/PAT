#include <iostream>
#include <vector>
#include <utility>
using namespace std;

size_t N; // The number of data points.
int    T; // The threshold.

int main() {
	cin >> N >> T;
	vector<int> points(N);
	for (size_t i = 0; i < N; ++i)
		cin >> points[i];
	
	using Segment_t = pair<size_t, size_t>; // Segment type: [first, second]
	vector<Segment_t> segments;

	bool active = false; // Indicates whether a segment is on recording.
	size_t start = 0, end = 0;
	int max_point = -1;
	for (size_t i = 0; i < N; ++i) {
		if (points[i] > max_point)
			max_point = points[i];
		if (points[i] > T) {
			if (active) continue;
			else {
				active = true; // Start a record.
				start = i;
			}
		}
		else {
			if (active) {
				active = false; // End the current active record.
				end = i;
				segments.emplace_back(start, end - 1);
			}
			else continue;
		}
	}
	if (active) {
		// End the last record.
		active = false;
		end = N;
		segments.emplace_back(start, end - 1);
	}
	if (segments.empty()) cout << max_point << endl;
	for (Segment_t seg : segments)
		cout << "[" << seg.first << ", " << seg.second << "]" << endl;
	return 0;
}