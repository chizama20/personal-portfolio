import pygame
from pygame.locals import *

# Constants
FPS = 60
BACKGROUND_SPEED = 2
SCREEN_WIDTH = 400
SCREEN_HEIGHT = 600
GRAVITY = 0.5
JUMP_STRENGTH = -10

class Bird:
    def __init__(self, image_path, x, y):
        self.image = pygame.image.load(image_path)
        self.image = pygame.transform.scale(self.image, (50, 50))
        self.rect = self.image.get_rect(topleft=(x, y))
        self.velocity = 0
        
    def update(self):
        self.velocity += GRAVITY
        self.rect.y += self.velocity
        
    def jump(self):
        self.velocity = JUMP_STRENGTH
        
    def draw(self, surface):
        surface.blit(self.image, self.rect)

class ScrollingBackground:
    def __init__(self, image_path, surface):
        self.surface = surface
        self.background = pygame.image.load(image_path)
        self.background = pygame.transform.scale(self.background, (surface.get_width(), surface.get_height()))
        self.background_x = 0

    def update(self):
        # Move background to the left
        self.background_x -= BACKGROUND_SPEED
        # Reset background position if it goes off screen
        if self.background_x <= -self.surface.get_width():
            self.background_x = 0

    def draw(self):
        # Draw background image
        self.surface.blit(self.background, (self.background_x, 0))
        # Draw the second part of the background image
        self.surface.blit(self.background, (self.background_x + self.surface.get_width(), 0))

if __name__ == "__main__":
    pygame.init()

    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
    pygame.display.set_caption("Flappy Bird")

    clock = pygame.time.Clock()

    # Initialize the scrolling background
    bg = ScrollingBackground(r"flappy birds/resources/flappy-bird-background-png-8.png", screen)
    bird = Bird(r"flappy birds/resources/Flappy-Bird-PNG-Photo.png", 100, SCREEN_HEIGHT // 2)

    running = True

    while running:
        for event in pygame.event.get():
            if event.type == QUIT:
                running = False      
            if event.type == KEYDOWN:
                if event.key == K_ESCAPE:
                    running = False
                if event.key == K_SPACE:
                    bird.jump()

        # Update background position
        bg.update()
        
        # Update bird position
        bird.update()

        # Draw everything
        bg.draw()
        bird.draw(screen)

        # Update the display
        pygame.display.flip()

        # Control the frame rate
        clock.tick(FPS)

    pygame.quit()

