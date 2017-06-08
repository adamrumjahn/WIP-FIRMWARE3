
int TuningDataSpeed = 2;	// 0 = off, 1 = 0.5s, 2=0.1s

void TuningData100MS() {
	if (TuningDataSpeed == 2) {
		SendTuningData();
	}	
}


void TuningData500MS() {
	if (TuningDataSpeed == 1) {
		SendTuningData();
	}
}

void SendTuningData() {
	// Position data will only be valid for single axis moves, but that's what tuning is, so should be ok
	//int32_t xPos = Printer::currentPositionSteps[X_AXIS];
	//int32_t yPos = Printer::currentPositionSteps[Y_AXIS];
	int32_t zPos = Printer::currentPositionSteps[Z_AXIS];
	//
	//if (PrintLine::hasLines() && (PrintLine::cur->stepsRemaining > 0 && !PrintLine::cur->isNoMove())) {
	//	if (PrintLine::cur->isMoveOfAxis(X_AXIS)) xPos = Printer::destinationSteps[X_AXIS] + PrintLine::cur->delta[X_AXIS];
	//	if (PrintLine::cur->isMoveOfAxis(Y_AXIS)) yPos = Printer::destinationSteps[Y_AXIS] + PrintLine::cur->delta[Y_AXIS];;
	//	if (PrintLine::cur->isMoveOfAxis(Z_AXIS)) zPos = Printer::destinationSteps[Z_AXIS] + PrintLine::cur->delta[Z_AXIS];;
	//}

	///*xPos = xPos / XAXIS_STEPS_PER_MM;
	//yPos = yPos / YAXIS_STEPS_PER_MM;
	//zPos = zPos / ZAXIS_STEPS_PER_MM;*/

	//Serial.print(xPos);
	//Serial.print("*");
	//Serial.print(yPos);
	//Serial.print("*");
	//Serial.print(zPos);

	HAL::SelectSPIChip(SPI_Z);
	uint32_t val = 0;
	Printer::stepperZ.read_REG(TMC_REG_DRV_STATUS, &val);
	// select just the SG Result from the status reg
	val = val & 0b1111111111;
	HAL::SelectSPIChip(SPI_NONE);
	Serial.print(val);
	Serial.print("*");
	Serial.print(zPos);
	Serial.print('\n');	
}