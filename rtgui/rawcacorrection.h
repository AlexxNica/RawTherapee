/*
 *  This file is part of RawTherapee.
 *
 *  Copyright (c) 2004-2010 Gabor Horvath <hgabor@rawtherapee.com>
 *
 *  RawTherapee is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  RawTherapee is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with RawTherapee.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _RAWCACORRECTION_H_
#define _RAWCACORRECTION_H_

#include <gtkmm.h>
#include "adjuster.h"
#include "checkbox.h"
#include "toolpanel.h"

class RAWCACorr : public ToolParamBlock, public AdjusterListener, public CheckBoxListener, public FoldableToolPanel
{

protected:
    CheckBox* caAutocorrect;
    Adjuster* caStrength;
    Adjuster* caRed;
    Adjuster* caBlue;

public:

    RAWCACorr ();

    void read                (const rtengine::procparams::ProcParams* pp, const ParamsEdited* pedited = nullptr);
    void write               (rtengine::procparams::ProcParams* pp, ParamsEdited* pedited = nullptr);
    void setBatchMode        (bool batchMode);
    void setDefaults         (const rtengine::procparams::ProcParams* defParams, const ParamsEdited* pedited = nullptr);
    void setAdjusterBehavior (bool caadd);
    void trimValues          (rtengine::procparams::ProcParams* pp);

    void adjusterChanged     (Adjuster* a, double newval);
    void checkBoxToggled     (CheckBox* c, CheckValue newval);
};

#endif
