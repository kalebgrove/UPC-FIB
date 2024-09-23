#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Here you can add more includes if you wish.
// ...

using namespace std;

struct Image {
  string name;
  int depth;
  int i, j;
  vector<string> v;
};

typedef vector<Image> ListImages;

// Auxiliary functions (you can add more functions if you wish)

// Pre: The input has a description of an image with this format:
//      - First line: name depth i j
//      - Second line: n m
//      - n lines with m characters each (the contents of v)
Image readImage() {
  Image image;
  cin >> image.name >> image.depth >> image.i >> image.j;
  int n, m;
  cin >> n >> m;
  image.v = vector<string> (n);
  for (int i = 0; i < n; ++i)  cin >> image.v[i];
  return image;
}

// Pre: listimages contains a list of valid images.
// Post: N,M are the dimensions of the minimum board such that
//       all of those images fit in it.
void computeMinimumBoardDimensions(const ListImages &listimages, int &N, int &M) {
  N = 0;
  M = 0;
  for (int d = 0; d < int(listimages.size()); ++d) {
    const Image image = listimages[d];
    N = max(N, image.i+int(image.v.size()));
    M = max(M, image.j+int(image.v[0].size()));
  }
}

// Pre:  image valid and board is valid and image fits in board.
// Post: image has been drawn on board. Nothing else has changed.
void drawImage(const Image &image, vector<string> &board) {
  // Implement this function.
  for (int i = 0; i < int(image.v.size()); ++i) {  
    for (int j = 0; j < int(image.v[0].size()); ++j) {
      if (image.v[i][j] != '.')  board[i+image.i][j+image.j] = image.v[i][j];
    }
  }
}

// Pre:  image1, image2 represent valid images.
// Post: Returns true iff one of the following conditions holds:
//         - depth of image1 is strictly bigger than depth of image2.
//         - image1 and image2 have same depth, but image1 has smaller name than image2.
bool compareImages(Image image1, Image image2) {
  // Implement this function.
  if (image1.depth != image2.depth) return image1.depth > image2.depth;
  return image1.name < image2.name;
}

void drawListImages(ListImages &listimages) {
  sort(listimages.begin(), listimages.end(), compareImages);
  int N, M;
  computeMinimumBoardDimensions(listimages, N, M);
  vector<string> board(N, string(M, '.'));
  for (int i = 0; i < int(listimages.size()); ++i)  drawImage(listimages[i], board);
  for (int i = 0; i < N; ++i)  cout << board[i] << endl;
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  ListImages listimages(n);
  for (int i = 0; i < n; i++)  listimages[i] = readImage();
  drawListImages(listimages);
}
