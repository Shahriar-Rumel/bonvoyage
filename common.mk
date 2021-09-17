OUT = Objects
SEARCHPATH += codes
vpath %.cpp $(SEARCHPATH)
vpath %.h $(SEARCHPATH)

DEPS += preprocessors.h structures.h variablesLevelOne.h variablesLevelTwo.h

_OBJS += drawLevelOneGameOver.o drawScoreBoard.o drawLevelOnePlayerName.o drawLife.o drawLevelOneCompleted.o variablesLevelOne.o variablesLevelTwo.o resetAll.o loadScoreFile.o drawWelcomeWindow.o drawNewgameWindow.o drawCoins.o  drawObstacle.o drawLevelTwoWindow.o drawLevelOneWindow.o updateScore.o updatePlayerName.o draw.o  collisionLevelOne.o collisionLevelTwo.o drawCoinsEffect.o drawLifeLoss.o  drawLevelTwoScoreBoard.o drawlevelTwoTracks.o drawLevelTwoCoins.o drawLevelTwoBombandDragon.o drawLevelTwoLife.o drawLevelTwoCompleted.o drawScoreBoardHub.o drawLevelTwoPlayerName.o drawControlsWindow.o drawLevelTwoGameOver.o
_OBJS += initiateLevelOneGameOver.o initiateScoreBoard.o initiateLife.o initiateLevelOneCompleted.o initiateWelcomeWindow.o initiateNewGameWindow.o initiateLevelTwoWindow.o initiateCoins.o  initiateObstacle.o initiateLevelOneWindow.o initialize.o inputs.o initiateCoinsEffect.o initiateLifeLoss.o initiateLevelTwoTracks.o initiateLevelTwoCoins.o initiateLevelTwoBombandDragon.o initiateLevelTwoLife.o initiateLevelTwoCompleted.o initiateLevelTwoScoreBoard.o initiateScoreBoardHub.o updateLevelTwoPlayerName.o initiateControlsWindow.o
_OBJS += main.o

OBJS = $(patsubst %,$(OUT)/%,$(_OBJS))

# top-level rule to create the program.
all: $(PROG)

# compiling other source files.
$(OUT)/%.o: %.cpp %.h $(DEPS)
	@mkdir -p $(OUT)
	$(CC) $(CFLAGS) $(CXXFLAGS) -c -o $@ $<
	
# cleaning everything that can be automatically recreated with "make".
clean:
	$(RM) -rf $(OUT) $(PROG)
