/*
 * Copyright (C) 2015  eBusiness Information
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

package mobi.designmyapp.arpigl.model;

import mobi.designmyapp.arpigl.engine.ArpiGlController;

/**
 * Identifies built-in shapes available in the DMA
 * {@link ArpiGlController}.
 *
 * @author Nicolas THIERION.
 */
public interface Shape {

    String getSid();


    enum Default implements Shape {
        BALLOON("balloon"), CUBE("cube"), PYRAMID("pyramid"), SPHERE("sphere"), NOTE("note");

        private String mSid;

        Default(String sid) {
            mSid = sid;
        }

        @Override
        public final String getSid() {
            return mSid;
        }
    }
}
