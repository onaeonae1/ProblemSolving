#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Person {
    int start, end;
};

// 우선순위 큐에서 사용될 자리 정보 구조체
struct Seat {
    int end_time, seat_number;
    bool operator<(const Seat& other) const {
        return end_time > other.end_time;  // 종료 시간이 빠른 순서대로 정렬
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;

    vector<Person> people(N);
    for (int i = 0; i < N; i++) {
        cin >> people[i].start >> people[i].end;
    }
    sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.start < b.start;
    });
    vector<int> seat_usage;
    priority_queue<Seat> seats;
    priority_queue<int, vector<int>, greater<int>> available_seats;
    int next_seat_number = 0;

    for (int i = 0; i < N; i++) {
        int start = people[i].start;
        int end = people[i].end;

        // 현재 사용 가능한 자리 찾기 (종료된 자리 반환)
        while (!seats.empty() && seats.top().end_time <= start) {
            available_seats.push(seats.top().seat_number);  // 자리가 비어 있음을 저장
            seats.pop();
        }

        // 새로운 자리에 배정해야 하는 경우
        if (available_seats.empty()) {
            seat_usage.push_back(1);  // 새로운 자리에 1명 배정
            seats.push({ end, next_seat_number });
            next_seat_number++;
        }
        else {
            // 비어 있는 자리가 있는 경우
            int seat_number = available_seats.top();
            available_seats.pop();
            seat_usage[seat_number]++;
            seats.push({ end, seat_number });
        }
    }

    
    cout << next_seat_number << "\n";  // 최소 컴퓨터 개수
    for (int i = 0; i < next_seat_number; i++) {
        cout << seat_usage[i] << " ";
    }
    cout <<"\n";

    return 0;
}
