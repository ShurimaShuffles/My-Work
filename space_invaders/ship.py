import pygame


class Ship:

    def __init__(self,sa_game):

        self.move_left = False
        self.move_right = False

        self.screen = sa_game.screen
        self.screen_rect = sa_game.screen.get_rect()

        #load the space ship image
        self.image = pygame.image.load("ship.png")

        #set the image to an appropriate size
        self.shipsize = (70,140)
        self.image = pygame.transform.scale(self.image,self.shipsize)
        self.rect = self.image.get_rect()

        #set the midbottom value of the ship to be the same as the 
        #midbottom of the screen
        self.rect.midbottom = self.screen_rect.midbottom

    def blit(self):
        self.screen.blit(self.image,self.rect)

    #def moveL(self):
    #    self.rect.x -= 10

    #def moveR(self):
    #    self.rect.x += 10

    def update(self):
        if self.move_right == True and self.rect.x < (self.screen_rect.width - self.shipsize[0]) :
            self.rect.x +=1
        if self.move_left == True and self.rect.x > 0:
            self.rect.x -=1
