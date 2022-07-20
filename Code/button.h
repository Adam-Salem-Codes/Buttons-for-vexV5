
    typedef struct {
      int x;
      int y;
      int w;
      int h;
    }
      square;
            
    typedef struct {
      int x;
      int y;
    }
    point;
  class button
  {
    public: 
      square s;
      bool isDisabled;
      char* senderArgs;
      bool hasSender = false;
      void (*functionpointer)(void);
      void (*senderFunctionPointer)(char *);
      int CheckCollisions();
      typedef char *string;
      void setButtonDisabled(bool x);
      void clear();
      void setup(int x, int y, int width, int height, string text, void (*ptr)(void));
      void setup(square s, string text, void (*ptr)(void));
      void destroy();
      void setup(int x, int y, int width, int height, string text, void (*ptr)(char *), char *sender);
      void setup(square s, string text,  void (*ptr)(char *), char *sender);
  };
