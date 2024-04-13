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
//      - First line: name depth i j n m
//      - n lines with m characters each (the contents of v)
//        These characters are different from whitespace, as we use '.' to represent empty character.
Image readImage()
{
    Image image;
    int n, m; // These are the numbers that determine the length of the characters introduced in the console.
    cin >> image.name >> image.depth >> image.i >> image.j >> n >> m;
    image.v = vector<string> (n);
    for(int i = 0; i < n; ++i) {
        cin >> image.v[i];
    }
    return image;
}

// Pre: listimages contains a non-empty list of valid images.
// Post: N,M are the dimensions of the minimum board such that
//       all of those images fit in it.
//       In other words, N,M must be the minimum naturals satisfying that,
//       for each image in listimages,
//       if i,j are its location and n,m are the dimensions of its v,
//       then i+n<=N and j+m<=M must be satisfied,
void computeMinimumBoardDimensions(const ListImages &listimages, int &N, int &M) {
    N = 0, M = 0;
    for(int k = 0; k < listimages.size(); ++k) {
        N = max(N, int(listimages[k].i+listimages[k].v.size()));
        M = max(M, int(listimages[k].j+listimages[k].v[0].size()));
    }
}

// Pre:  image is valid and board is valid and image fits in board.
// Post: image has been drawn on board. Nothing else has changed.
//       Recall that occurrences of character '.' in image are not printed on board!
void drawImage(const Image &image, vector<string> &board)
{
    for(int i = 0; i < image.v.size(); ++i) {
        for(int j = 0; j < image.v[0].size(); ++j) {
            if(image.v[i][j] != '.') board[i+image.i][j+image.j] = image.v[i][j];
        }
    }
}

// Pre:  image1, image2 represent valid images.
// Post: Returns true iff one of the following conditions holds:
//         - depth of image1 is strictly bigger than depth of image2.
//         - image1 and image2 have same depth, but image1 has smaller name than image2.
bool compareImages(Image image1, Image image2)
{
    if(image1.depth != image2.depth) return image1.depth > image2.depth;
    return image1.name < image2.name;
}

// Pre: listimages has a list of valid images.
// Post: prints on the output the result of drawing all of those
//       images on the minimum board such that all of them fit in,
//       and sorted by depth and name.
void drawListImages(const ListImages &listimages)
{
 sort(listimages.begin(), listimages.end(), compareImages);
 int N, M;
 computeMinimumBoardDimensions(listimages, N, M);
 vector<string> board(N, string(M, '.'));
 for (int i = 0; i < int(listimages.size()); i++) drawImage(listimages[i], board);
 for (int i = 0; i < N; i++) cout << board[i] << endl;
 cout << endl;
}

int main()
{
 int n;
 cin >> n;
 ListImages listimages(n);
 for (int i = 0; i < n; i++) listimages[i] = readImage();
 drawListImages(listimages);
}