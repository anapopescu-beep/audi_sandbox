-- sets the unused bit pattern of ISignalPdus to 255
update SYS_PDU set unusedBitPattern = 255 where PDU_Type = "SignalIPdu"; 