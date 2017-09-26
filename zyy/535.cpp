class Solution {
  public:
    /*
      This is an open question, so I do not code it seriously.
      The points are two:
        1. Hash from longUrl to shortUrl
        2. State for convert shortUrl back
      The first point aims to use shortest url and the second
      aims to restore original url. I don't know how to use stateless
      method and I think it is not possible to shorten url with stateless
      method perfectly.
     */
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
