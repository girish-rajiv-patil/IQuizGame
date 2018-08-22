#include "Random.h"

float Random::valueBetween(float min, float max) {
	return (((float) rand() / 0xFFFFFFFFu) * (max - min)) + min;
}
