#include <iostream>

using namespace std; 

class Button {
public:
  virtual void render() = 0; 
};

class ScrollBar {
public:
  virtual void render() = 0; 
};

class WinButton : public Button {
public: 
  void render() {
    cout << "Rendering windows button. " << endl; 
  }
};

class MacButton : public Button {
public: 
  void render() {
    cout << "Rendering mac button. " << endl; 
  }
};

class MotifButton : public Button {
public: 
  void render() {
    cout << "Rendering motif button. " << endl; 
  }
}; 

class WinScrollBar : public ScrollBar {
public: 
  void render() {
    cout << "Rendering windows scrollbar. " << endl;
  }
};

class MacScrollBar : public ScrollBar {
public: 
  void render() {

    cout << "Rendering mac scroll bar. " << endl;
  }
};

class MotifScrollBar : public ScrollBar {
public:
  void render() {
    cout << "Rendering motif scroll bar. " << endl; 
  }
};

class GUIFactory {
public:
  virtual Button* createButton() = 0;

  virtual ScrollBar* createScrollBar() = 0; 
};

class WinGUIFactory : public GUIFactory {
public: 
  Button* createButton() {
    return new WinButton(); 
  }

  ScrollBar* createScrollBar() {
    return new WinScrollBar(); 
  }
};

class MacGUIFactory : public GUIFactory {
public: 
  Button* createButton() {
    return new MacButton(); 
  }

  ScrollBar* createScrollBar() {
    return new MacScrollBar(); 
  }
};

class MotifGUIFactory : public GUIFactory {
public: 
  Button* createButton() {
    return new MotifButton();
  }

  ScrollBar* createScrollBar() {
    return new MotifScrollBar(); 
  }
};

int main() {
  GUIFactory* factory = NULL; 

  // windows factory.
  factory = new WinGUIFactory(); 
  factory->createButton()->render(); 
  factory->createScrollBar()->render(); 
  cout << endl; 

  // mac factory. 
  factory = new MacGUIFactory(); 
  factory->createButton()->render(); 
  factory->createScrollBar()->render(); 
  cout << endl; 

  // motif factory. 
  factory = new MotifGUIFactory(); 
  factory->createButton()->render(); 
  factory->createScrollBar()->render(); 
  cout << endl; 

  return 0; 
}
