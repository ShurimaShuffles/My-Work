import pygame
from pygame.sprite import Sprite


class alien(Sprite):
    speed = 1.0

    def __init__(self, sa_game, x):
        super().__init__()

        self.move_left = False
        self.move_right = True

        self.screen = sa_game.screen
        self.screen_rect = sa_game.screen.get_rect()

        # load the space ship image
        self.image = pygame.image.load("alien.png")

        # set the image to an appropriate size
        self.shipsize = (60, 60)
        self.image = pygame.transform.scale(self.image, self.shipsize)
        self.rect = self.image.get_rect()
        self.rect.x += x

    def blit(self):
        self.screen.blit(self.image, self.rect)

    def update(self):
        # Move right until you reach the boundary
        if self.move_right:
            self.rect.x += 1
            if self.rect.x > (self.screen_rect.width - self.shipsize[0]):
                self.move_right = False
                self.rect.y += 60
                self.move_left = True

        if self.move_left:
            self.rect.x -= 1
            if self.rect.x < 0:
                self.move_left = False
                self.rect.y += 60
                self.move_right = True

    def delete_ship(self):
        self.shipsize = (0, 0)

    def draw_alien(self):
        self.screen.blit(self.image, self.rect)
