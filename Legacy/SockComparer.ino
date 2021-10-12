/** This file stores the sock-ids and couples them to a basket. It also compares sock-ids to see check if there is a match.
If there is a match, then it outputs the corresponding basket. */

SockScanner sockScanner;
SockScanner[] sockIDs; // TODO Might have a problem since arrays do not have flexible length. Consider using lists, or just initialize at max amount of baskets.
void setup() {
//TODO
}

void scanSock() {
  sockScanner.createSockID(sockScanner.readRGB(), sockScanner.readIR());
}

void addSockID(int n) {
  SockIDS[n] = sockScanner.getSockID();
}

int compareSocks(SockScanner[] sockID) {
  //TODO create epic comparison algorithm to compare socks
  return 0; //Placeholder, should return the right basket.
}
void loop() {
//TODO
}
