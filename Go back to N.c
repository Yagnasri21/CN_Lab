#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define SLEEP(x) Sleep(1000 * (x))
#else
#include <unistd.h>
#define SLEEP(x) sleep(x)
#endif

int main() {
    int sent_upto = 0;
    int ack_expected = 0;
    int i, TOTAL_FRAMES, WINDOW_SIZE;

    printf("Enter the Total Frames: ");
    scanf("%d", &TOTAL_FRAMES);
    printf("Enter the WINDOW_SIZE: ");
    scanf("%d", &WINDOW_SIZE);

    srand((unsigned int)time(NULL));

    printf("\n=== Sliding Window with Go-Back-N ARQ Simulation ===\n\n");

    while (ack_expected < TOTAL_FRAMES) {
        // Send frames in the window
        for (i = sent_upto; i < ack_expected + WINDOW_SIZE && i < TOTAL_FRAMES; i++) {
            printf("Sender: Sending Frame %d\n", i);
        }
        sent_upto = i;

        // Simulate frame loss with probability
        if ((rand() % 4 == 0) && (sent_upto > ack_expected)) {
            printf("Receiver: Frame %d lost! -> Go-Back-N triggered\n", ack_expected);
            printf("Sender: Retransmitting from Frame %d onwards...\n\n", ack_expected);
            sent_upto = ack_expected;
        } else if (sent_upto > ack_expected) {
            printf("Receiver: ACK received for Frame %d\n\n", ack_expected);
            ack_expected++;
        }
        SLEEP(1);
    }

    printf("=== All %d Frames sent successfully with Go-Back-N! ===\n", TOTAL_FRAMES);
    return 0;
}
