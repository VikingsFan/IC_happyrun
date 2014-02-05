#include "main.h"
#include "AppDelegate.h"
#include "CCEGLView.h"

#include "WordsHelper.h"

USING_NS_CC;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
	wordsHelper.setNumber(WORD_STOCK_NUMBER::FOUR);
	std::string str = wordsHelper.loadWords();
	wordsHelper.getRandWords(13);
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // create the application instance
    AppDelegate app;
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
	eglView->setViewName(str.c_str());
    eglView->setFrameSize(480, 320);
    return CCApplication::sharedApplication()->run();
}
