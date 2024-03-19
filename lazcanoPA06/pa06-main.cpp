#include "class.h"

/*
 *
 * Main Function -
 *
 * Test Program for container class that provides key/data pairs for evaluation.
 *
 *
 * */

int main(int inputCount, char* inputPointersArray[], char* envPointersArray[]) {
  int num = 0;
  cout << "Starting Main Function" << endl;
  if (inputCount > 1) {
    num = atoi(inputPointersArray[inputCount - 1]);
  } else {
    num = 5;
  }
  Container<string, string> cont(num);
  Element<string, string> temp, temp2;
  bool b;
  // number of elements coming from the command line will be 5
  // push three elements into container
  temp.key = "111";
  temp.data = "aaa";
  temp.priority = 7;
  cont.push(temp);
  sleep(1);
  temp.key = "222";
  temp.data = "bbb";
  temp.priority = 10;
  cont.push(temp);
  sleep(1);
  temp.key = "333";
  temp.data = "ccc";
  temp.priority = 4;
  cont.push(temp);
  sleep(1);
  // test size functions
  cout << "main: current size of container " << cont.size() << endl;
  cout << "main: max size of container " << cont.max_size() << endl;
  // test get_front
  b = cont.get_front(temp2);
  cout << "main: get_front gets " << temp2.key << " " << temp2.data << endl;
  // test get_back
  b = cont.get_back(temp2);
  cout << "main: get_back gets " << temp2.key << " " << temp2.data << endl;
  // test start and get_next functions
  cont.start();
  while (cont.get_next(temp2)) {
    cout << "main: loop #1, data ->" << temp2.key << " " << temp2.data << " "
         << temp2.timestamp << " " << temp2.priority << endl;
  }
  cout << "main: after loop #1" << endl;
  // try to push_back three more elements into C
  // the first two should work; the last one should fail
  temp.key = "444";
  temp.data = "ddd";
  temp.priority = 5;
  cont.push(temp);
  sleep(1);
  temp.key = "555";
  temp.data = "eee";
  temp.priority = 1;
  cont.push(temp);
  sleep(1);
  temp.key = "666";
  temp.data = "fff";
  temp.priority = 20;
  b = cont.push(temp);
  if (!b) {
    cout << "main: success, push_back failed on push_back # 6" << endl;
  } else {
    cout << "main: failed, push_back returned true on push_back # 6" << endl;
  }
  // test sequential retrieval
  cont.start();
  while (cont.get_next(temp2)) {
    cout << "main: loop #2, data ->" << temp2.key << " " << temp2.data << " "
         << temp2.timestamp << " " << temp2.priority << endl;
  }
  cout << "main: after loop #2" << endl;
  // test retrieve_by_key; search for key that exists
  temp2.key = "333";
  b = cont.get_by_key(temp2);
  if (b) {
    cout << "main: success, after retrieve_by_key for key 333, got "
         << temp2.key << " " << temp2.data << endl;
  } else {
    cout << "main: failed, retrieve_by_key for key 333 failed" << endl;
  }
  // test retrieve_by_key, search for key that doesn't exist
  temp2.key = "123";
  b = cont.get_by_key(temp2);
  if (b) {
    cout << "main: failed, after get_by_key for nonexistent key, returned found"
         << endl;
  } else {
    cout << "main: success, get_by_key for nonexistent key failed" << endl;
  }
  // test get_highest_priority
  b = cont.get_highest_priority(temp2);
  cout << "main: after get_highest_priority, got " << temp2.key << " "
       << temp2.data << endl;
  // test get via subscript; valid subscript
  try {
    temp2 = cont[4];
    cout << "main: retrieved element [4], got " << temp2.key << " "
         << temp2.data << endl;
  } catch (string& e) {
    cout << "main: failed, [4] threw exception - " << e << endl;
  }
  // test get via subscript; invalid subscript
  try {
    temp2 = cont[12];
    cout << "main: retrieved element [12], got " << temp2.key << " "
         << temp2.data << endl;
  } catch (string& e) {
    cout << "main: success, [12] threw exception - " << e << endl;
  }
  cout << "main ending" << endl;
  return 0;
}
