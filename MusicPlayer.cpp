/* 
     Here is the DSA project - A music player this shows how our music player works logically in our system
     concepts used - LINKED LIST, OOPS, DATA STRUCTURES, SEARCHING.
*/


#include<bits/stdc++.h>

using namespace std;

// here's how our music is stored in form of class have song name and artist name 

class Song {
public:
    string title;
    string artist;

    Song(string t, string a) : title(t), artist(a) {}
};

/*   this is our playlist from which music will be played , we have a list of the songs that are defined above 
     it will contain all the songs. And an iterator to access to song
*/

class Playlist {
    list<Song> songs;
    list<Song>::iterator current;

public:
    Playlist() {
        current = songs.end();
    }

    void addSong(const Song& song) {
        songs.push_back(song);
        if (songs.size() == 1) {
            current = songs.begin();
        }
    }

    void play() {
        if (songs.empty()) {
            cout << "Playlist is empty." << endl;
        } else {
            cout << "Playing: " << current->title << " by " << current->artist << endl;
        }
    }

    void next() {
        if (songs.empty()) {
            cout << "Playlist is empty." << endl;
        } else {
            current++;
            if (current == songs.end()) {
                current = songs.begin(); // Loop back to start
            }
            play();
        }
    }

    void previous() {
        if (songs.empty()) {
            cout << "Playlist is empty." << endl;
        } else {
            if (current == songs.begin()) {
                current = songs.end();
            }
            current--;
            play();
        }
    }

    void pause() {
        if (!songs.empty()) {
            cout << "Paused: " << current->title << endl;
        }
    }

    void searchSong(string title) {
        for (auto it = songs.begin(); it != songs.end(); ++it) {
            if (it->title == title) {
                cout << "Found: " << it->title << " by " << it->artist << endl;
                current = it;
                return;
            }
        }
        cout << "Song not found." << endl;
    }

    void showPlaylist() {
        if (songs.empty()) {
            cout << "Playlist is empty." << endl;
            return;
        }
        cout << "Playlist:" << endl;
        for (const auto &song : songs) {
            cout << song.title << " by " << song.artist << endl;
        }
    }
};


int main() {
    Playlist playlist;

    // example of songs..
    playlist.addSong(Song("Tum hi ho", "Arjit singh"));
    playlist.addSong(Song("Pehle bhi mai", "Vishal mishra"));
    playlist.addSong(Song("Tune jo na kaha", "Mohit chauhan"));
    playlist.addSong(Song("Sun sathiyan", "Divya kumar"));

    int choice;
    string title, artist;

    while (true) {
        cout << "\n1. Play\n2. Next\n3. Previous\n4. Pause\n5. Search\n6. Show Playlist\n7. Add Song\n0. Exit\n\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                playlist.play();
                break;
            case 2:
                playlist.next();
                break;
            case 3:
                playlist.previous();
                break;
            case 4:
                playlist.pause();
                break;
            case 5:
                cout << "Enter song title to search: ";
                cin>>title;
                playlist.searchSong(title);
                break;
            case 6:
                playlist.showPlaylist();
                break;
            case 7:
                cout << "Enter song title: ";
                cin>>title;
                cout << "Enter artist: ";
                cin>>artist;
                playlist.addSong(Song(title, artist));
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }

    }
    return 0;
}
