#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

class MusicRecommender {
private:
map<string, vector<string>> moodSongs;

public:
MusicRecommender() {
// Happy songs playlist
moodSongs["happy"] = {
"https://open.spotify.com/playlist/4Ob8EsjlOCniaxISzw34su?si=zX5FmDwtTMySEecD6j3DJg&pi=QaVJwKtET1O_v", // playlist
};
// Sad songs playlist
moodSongs["sad"] = {
"https://open.spotify.com/playlist/7dARpPZwPc5bsoxjwid1Th?si=ZEXnpikgRJm-EaUH6Xq6UQ&pi=mRj3_eblRyu3M", // playlist
};
// Relaxed songs playlist
moodSongs["relaxed"] = {
"https://open.spotify.com/playlist/1nrrgu3smArPL2IiUjKcnE?si=sZg6QBkcTgKPHkx1ONqIAw" ,// playlist
};
// Energetic songs playlist
moodSongs["energetic"] = {
"https://open.spotify.com/playlist/1v2xxHpK5c6YTUIUDxg7oT?si=VlB5qvYITd6SgsH5NcJYMQ&pi=39M93tTfT7mc9" // playlist
};
}

void recommend(const string &mood) {
auto it = moodSongs.find(mood);
if (it != moodSongs.end()) {
const vector<string> &songs = it->second;
if (songs.empty()) {
cout << "No songs available for this mood.\n";
return;
}
int index = rand() % songs.size();
string url = songs[index];
cout << "🎶 Opening recommended song for mood (" << mood << "):\n" << url << endl;

#ifdef _WIN32
string cmd = string("start \"\" \"") + url + "\"";
system(cmd.c_str());
#elif __APPLE__
system((string("open \"") + url + "\"").c_str());
#else
system((string("xdg-open \"") + url + "\"").c_str());
#endif
} else {
cout << "Sorry, no songs found for this mood.\n";
}
}
};

int main() {
srand(static_cast<unsigned int>(time(nullptr)));

MusicRecommender mr;
string mood;
cout << "Enter your mood (happy, sad, relaxed, energetic): ";
getline(cin, mood);

for (char &c : mood) c = static_cast<char>(tolower(c));

mr.recommend(mood);
return 0;
}
