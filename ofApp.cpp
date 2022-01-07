#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(255);
	ofSetColor(0);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	int span = 60;
	for (int x = span * -5; x < span * 5; x += span) {

		for (int y = span  * -5; y < span * 5; y += span) {

			int r = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.0035), 0, 1, 0, 4);
			auto location = glm::vec2(x, y);

			if (r == 1) {

				location += glm::vec2(span, 0);
			}
			else if (r == 2) {

				location += glm::vec2(span, span);
			}
			else if (r == 3) {

				location += glm::vec2(0, span);
			}

			int deg_start = r * 90;
			ofBeginShape();
			for (int deg = deg_start; deg <= deg_start + 90; deg += 1) {

				auto radius = span * 0.5;
				ofVertex(location + glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
			}
			ofVertex(location);
			ofEndShape(true);

			r = (r + 2) % 4;

			location = glm::vec2(x, y);
			if (r == 1) {

				location += glm::vec2(span, 0);
			}
			else if (r == 2) {

				location += glm::vec2(span, span);
			}
			else if (r == 3) {

				location += glm::vec2(0, span);
			}

			deg_start = r * 90;
			ofBeginShape();
			for (int deg = deg_start; deg <= deg_start + 90; deg += 1) {

				auto radius = span * 0.5;
				ofVertex(location + glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
			}
			ofVertex(location);
			ofEndShape(true);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}