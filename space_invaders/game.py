import pygame
import sys
from alien import alien
from blast import blast
from ship import Ship


class Game:
    def __init__(self):
        pygame.init()

        # get a Surface object for the screen
        size = (1200, 800)

        self.screen = pygame.display.set_mode(size)
        self.screen_rect = self.screen.get_rect()

        # set the caption for the screen
        pygame.display.set_caption("Space Aliens: CS 328 Assignment 2 Brandon Lavoie")

        # set the background color
        self.bg_color = (50, 90, 200)

        self.spaceship = Ship(self)
        self.blasts = pygame.sprite.Group()
        self.aliens = pygame.sprite.Group()

    def fire_laser_blast(self):
        myBlast = blast(self)
        sound = pygame.mixer.Sound('8-bit-laser.wav')
        sound.set_volume(0.3)
        sound.play()
        self.blasts.add(myBlast)

    def spawn_aliens(self, x):
        alien_invader = alien(self, x)
        self.aliens.add(alien_invader)

    def start(self):

        for x in range(5):
            x *= 120
            self.spawn_aliens(x)

        # Play the music of the game
        sound = pygame.mixer.Sound('8-bit-music.wav')
        sound.set_volume(0.5)
        sound.play()

        point_count = 0
        test = True
        while 1:  # event loop

            # spin through all the events looking for quit
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    sys.exit()
                if event.type == pygame.KEYDOWN:

                    # Move left
                    if event.key == pygame.K_LEFT:
                        self.spaceship.move_left = True

                    # Move right
                    if event.key == pygame.K_RIGHT:
                        self.spaceship.move_right = True

                    # Go Pew
                    if event.key == pygame.K_SPACE:
                        self.fire_laser_blast()



                elif event.type == pygame.KEYUP:
                    self.spaceship.move_left = False
                    self.spaceship.move_right = False

            # erase the screen by filling it with the color specified earlier
            self.screen.fill(self.bg_color)
            self.spaceship.update()
            self.aliens.update()
            self.blasts.update()

            # Display lasers
            for b in self.blasts.sprites():
                b.draw_laser()

            # Display Aliens
            for b in self.aliens.sprites():
                b.draw_alien()

            # Display the ship
            self.spaceship.blit()

            # If blast hit alien, alien go boom!
            if pygame.sprite.groupcollide(self.blasts, self.aliens, True, True):
                sound = pygame.mixer.Sound('8-bit-explosion.wav')
                sound.set_volume(0.5)
                sound.play()
                point_count += 1

            # If alien collide with spaceship, you lose!
            if pygame.sprite.spritecollideany(self.spaceship, self.aliens):
                # Stop background music
                pygame.mixer.pause()
                pygame.mixer.unpause()

                # You lost music
                sound = pygame.mixer.Sound('defeat.wav')
                sound.set_volume(0.5)
                sound.play()

                # You lose and point screen
                font = pygame.font.SysFont('timesnewroman', 60, True, False)
                text = font.render('GAME OVER', True, (250, 20, 10), (60, 60, 60))
                point_message = 'You scored %d points!' % point_count
                point_text = font.render(point_message, True, (250, 20, 10), (60, 60, 60))

                text_rect = text.get_rect()
                text_rect.midtop = self.screen_rect.midtop
                text_rect.y += 200

                point_rect = point_text.get_rect()
                point_rect.midtop = self.screen_rect.midtop
                point_rect.y += 300

                self.screen.blit(text, text_rect)
                self.screen.blit(point_text, point_rect)

            # YAY, you won
            if point_count == 5:
                # Stop background music
                pygame.mixer.pause()
                pygame.mixer.unpause()

                # You won music
                sound = pygame.mixer.Sound('victory.wav')
                sound.set_volume(1)
                sound.play()

                font = pygame.font.SysFont('timesnewroman', 60, True, False)
                text = font.render('VICTORY!', True, (250, 20, 10), (60, 60, 60))
                point_message = 'You scored %d points!' % point_count
                point_text = font.render(point_message, True, (250, 20, 10), (60, 60, 60))

                text_rect = text.get_rect()
                text_rect.midtop = self.screen_rect.midtop
                text_rect.y += 200

                point_rect = point_text.get_rect()
                point_rect.midtop = self.screen_rect.midtop
                point_rect.y += 300

                self.screen.blit(text, text_rect)
                self.screen.blit(point_text, point_rect)

            # updates the screen
            pygame.display.flip()


"""This section looks at a special python variable called __name__
This variable is set when the program is executed.
If the value of __name__ is set to "__main__", 
then we know the file is being run as the main method for the program.
So, since we are the main program we'll create an instance of our class
and then call the start() method."""
if __name__ == '__main__':
    myGame = Game()
    myGame.start()
