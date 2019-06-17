class Display {
public:
	void display();
	void screenInit();
	void update();

	void setCursorPosition(int, int);
	void textColor(int, int);
private:
	void drawUI(int);
	
	void clearScreen();
	void hideCursor();
};