// torrent.h
// 2016 .7. 28

#ifndef _TORRENT_H_
#define _TORRENT_H_
#include <iostream>
#include <vector>

using namespace std;

class Torrent {
  public:
    Torrent();
    Torrent(const Torrent& torrent);
    Torrent(const string& name, int maxSize, int seeder);

    string name() const;  // return name of the torrent file;
    int seeder() const;  // return the number of seeder;
    int maxSize() const; // return the size when downloading completed;
    int currentSize() const;

    // adjust currentSize_ and return it;
    // return -1 if download completed;
    int download(int _second);

  private:
    string name_;
    int seeder_, maxSize_, currentSize_;
};

class RatedTorrent : public Torrent {
  public:
    RatedTorrent();
    RatedTorrent(const Torrent& torrent);
    RatedTorrent(const string& name, int maxSize, int seeder, int rating);

    // return name_ + asterisk. ex) madMax(***) max * == 5;
    string name() const;
    void setRate(int rating);
    int rating() const;   // return rating_;

  private:
    int rating_;
};

class TorrentClient {
 public:
  TorrentClient();
  void printTorrent() const;

  // return true if rating succeeded, false if there's error
  // like name not found in torrents_;
  bool ratingTorrent(const string& name, int rating);

  // add torrent or ratedTorrent to private vectors;
  void addTorrent(Torrent& torrent);
  void addRatedTorrent(RatedTorrent& ratedTorrent);
  void deleteTorrent(const string& name);

  // download all torrent files in vectors;
  // files whose downloading completed -> remove;
  void downloadTorrent(const int second);

 private:
  vector<Torrent> torrents_;  // a vector contains torrent class;
  vector<RatedTorrent> ratedTorrents_;  // a vector contains ratedTorrent class;
};

istream& operator>>(istream& is, Torrent& torrent);
istream& operator>>(istream& is, RatedTorrent& ratedTorrent);


#endif  // _TORRENT_H_
